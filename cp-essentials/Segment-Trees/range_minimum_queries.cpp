#include <bits/stdc++.h>
using namespace std;

// finding summation
struct SegmentTree {
	vector<int> st;
	int n;

	void init(int _n) {
		n = _n;
		st.resize(4 * n, 0);
	}

	void build(int start, int end, int node, vector<int> &v) {
		// leaf node has start = end
		if(start == end) {
			st[node] = v[start];
			return;
		}

		int mid = (start + end) / 2;
		// left subtree is start to mid
		build(start, mid, 2 * node + 1, v);
		// right subtree is mid + 1 to end
		build(mid + 1, end, 2 * node + 2, v);

		// fill the current node
		st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);
	} 

	void build(vector<int> &v) {
		build(0, v.size() - 1, 0, v);
	}

	void update(int start, int end, int node, int index, int value) {
		if(start == end) {
			st[node] = value;
			return;
		}
		int mid = (start + end) / 2;
		if(index <= mid) {
			// left subtree
			update(start, mid, 2 * node + 1, index, value);
		} else {
			// right subtree
			update(mid + 1, end, 2 * node + 2, index, value);
		}
		st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);
	}

	void update(int x, int y) {
		update(0, n - 1, 0, x, y);
	}

	int query(int start, int end, int l, int r, int node) {
		// no overlap case
		if(start > r or end < l)
			return 0;

		// complete overlap case
		if(start >= l and end <= r)
			return st[node];

		// partial overlap case
		int mid = (start + end) / 2;
		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, end, l, r, 2 * node + 2);
		return min(q1, q2);
	}
	int query(int l, int r) {
		return query(0, n - 1, l , r, 0);
	}

};

vector<int> solve(int n, vector<int> arr, vector<vector<int>> queries) {
	SegmentTree tree;
	tree.init(n);
	tree.build(arr);
	vector<int> ans;
	for(auto i: queries) {
		int x = i[0], k = i[1], u = i[2];
		if(x == 2)
			ans.push_back(tree.query(k - 1, u - 1));
		else
			tree.update(k - 1, u);
	}
	return ans;
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> arr(n);
	vector<vector<int>> queries(q);
	for(auto &i: arr)
		cin >> i;
	for(int i = 0; i < q; i++) {
		int x, k, u;
		cin >> x >> k >> u;
		queries[i] = {x, k, u};
	}
	for(auto i: solve(n, arr, queries))
		cout << i << " ";
	return 0;
}
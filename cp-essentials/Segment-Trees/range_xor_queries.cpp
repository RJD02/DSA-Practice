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
		st[node] = st[node * 2 + 1] xor st[node * 2 + 2];
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
		st[node] = st[node * 2 + 1] xor st[node * 2 + 2];
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
		return q1 xor q2;
	}
	int query(int l, int r) {
		return query(0, n - 1, l , r, 0);
	}

};


vector<int> solve(int n, vector<int> a, vector<vector<int>> queries) {
	SegmentTree tree;
	tree.init(a.size());
	tree.build(a);
	vector<int> ans;
	// for(auto i: tree.st)
	// 	cout << i << " ";
	for(auto i: queries) {
		ans.push_back(tree.query(i[0] - 1, i[1] - 1));
	}
	return ans;
}

int main() {

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for(auto &i: v)
		cin >> i;
	vector<vector<int>> queries(q);
	for(int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		queries[i] = {x, y};
	}

	solve(n, v, queries);
	for(auto i: solve(n, v, queries))
		cout << i << " ";
	return 0;
}
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
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
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
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
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
		return q1 + q2;
	}
	int query(int l, int r) {
		return query(0, n - 1, l , r, 0);
	}

};

int main() {
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	SegmentTree tree;
	tree.init(v.size());
	tree.build(v);
	tree.update(4, 10);
	cout << tree.st[0] << endl;
	cout << tree.query(4, 4) << endl;
	cout << tree.query(2, 6);

	return 0;
}

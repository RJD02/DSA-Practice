#include <bits/stdc++.h>
using namespace std;

// finding summation
struct SegmentTree {
	vector<int> st, lazy;
	int n;

	void init(int _n) {
		n = _n;
		st.resize(4 * n, 0);
		lazy.resize(4 * n, 0);
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

	void update(int start, int end, int node, int l, int r, int value) {
		// non overlapping case
		if(start > r or end < l)
			return;

		// lazy  propagation / clear the lazy update
		if(lazy[node] != 0) {
			st[node] += lazy[node] * (end - start + 1);
			if(start != end) {
				lazy[2 * node + 1] += lazy[node];
				lazy[2 * node + 2] += lazy[node];
			}
			lazy[node] = 0;
		}

		// complete overlap
		if(start >= l and end <= r) {
			st[node] += value * (end - start + 1);
			if(start != end) {
				lazy[2 * node + 1] += value;
				lazy[2 * node + 2] += value;
			}
			return ;
		}

		// partial case
		int mid = (start + end) / 2;
		update(start, mid, 2 * node + 1, l, r, value);
		update(mid + 1, end, 2 * node + 2, l, r, value);
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
		return ;
	}

	void update(int x, int y, int z) {
		update(0, n - 1, 0, x, y, z);
	}

	int query(int start, int end, int l, int r, int node) {
		// no overlap case
		if(start > r or end < l)
			return 0;

		// Lazy propagation / clear the lazy update
		if(lazy[node] != 0) {
			// there are some pending updates
			st[node] += lazy[node] * (end - start + 1);
			if(start != end) {
				// propagate the updated value
				lazy[node * 2 + 1] += lazy[node];
				lazy[node * 2 + 2] += lazy[node];
			}
			lazy[node] = 0;

		}

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
	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	SegmentTree tree;
	tree.init(v.size());
	tree.build(v);
	tree.update(1, 3, 4);
	cout << tree.query(1, 3) << endl;
	return 0;
}
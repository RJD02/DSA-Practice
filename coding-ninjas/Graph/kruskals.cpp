#include <bits/stdc++.h>
using namespace std;

vector<int> parent, r;
vector<vector<int>> edgeList;
int n, e;

int find(int i) {
	if (parent[i] == -1) return i;
	return parent[i] = find(parent[i]);
}

void unite(int x, int y) {
	int s1 = find(x);
	int s2 = find(y);
	if (s1 != s2) {
		if (r[s1] < r[s2]) {
			parent[s1] = s2;
			r[s2] += r[s1];
		} else {
			parent[s2] = s1;
			r[s1] += r[s2];
		}
	}
}

void addEdge(int w, int x, int y) {
	edgeList.push_back({w, x, y});
}

void kruskalsMst() {
	r.resize(n, 1);
	parent.resize(n, -1);
	sort(edgeList.begin(), edgeList.end());
	for (auto edge : edgeList) {
		int w = edge[0];
		int x = edge[1];
		int y = edge[2];
		if (find(x) != find(y)) {
			unite(x, y);
			cout << min(x, y) << " " << max(x, y) << " " << w << endl;
			// ans += w;
		}
	}
	// cout << ans << endl;
}

int main() {
	// ios::sync_with_stdio(false);
	// int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(w, u, v);
	}
	kruskalsMst();
	return 0;
}
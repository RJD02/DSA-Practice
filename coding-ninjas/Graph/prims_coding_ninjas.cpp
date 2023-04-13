#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> adjList;
int n, e;

inline void addEdge(int u, int v, int w) {
	adjList[u].push_back({v, w});
	adjList[v].push_back({u, w});
}

void primsMst() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<int> wts(n, INT_MAX);
	vector<int> parent(n, -1);
	vector<bool> visited(n, false);
	pq.push({0, 0});
	wts[0] = 0;

	while (!pq.empty()) {
		int minVertex = pq.top().second;
		pq.pop();

		if (visited[minVertex]) continue;
		visited[minVertex] = true;
		for (auto i : adjList[minVertex]) {
			int node = i.first, nodeWt = i.second;
			if (!visited[node] and wts[node] > nodeWt) {
				parent[node] = minVertex;
				wts[node] = nodeWt;
				pq.push({wts[node], node});
				// visited[node] = true;
			}
		}
	}
	for (int i = 1; i < n; i++) {
		cout << min(i, parent[i]) << " " << max(i, parent[i]) << " " << wts[i] << endl;
	}
}

int main() {
	cin >> n >> e;
	adjList.resize(n);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w);
	}

	primsMst();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adjList;
int n, e;

inline void addEdge(int x, int y, int w) {
	adjList[x].push_back({y, w});
	adjList[y].push_back({x, w});
}

int primMst(int src = 0) {
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	vector<int> visited(n, false);
	int ans = 0;
	vector<int> parent(n);
	vector<int> dist(n);
	pq.push({0, src, -1}); // wt, src
	while (!pq.empty()) {
		// pick edge with min wt
		auto best = pq.top();
		pq.pop();
		int to = best[1], wt = best[0], from = best[2];
		if (visited[to]) {
			// discard the edge, so continue;
			continue;
		}
		// take current edge
		ans += wt;
		visited[to] = 1;
		// add the new edges to queue
		for (auto x : adjList[to]) {
			if (!visited[x.first]) {
				pq.push({x.second, x.first, to});
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> e;
	adjList.resize(n);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w);
	}
	primMst();
	return 0;
}
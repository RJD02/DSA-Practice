#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> adjList;
int V, E;

void addEdge(int u, int v, int w) {
	adjList[u].push_back({v, w});
	adjList[v].push_back({u, w});
}

void dijkstra(int src = 0) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	vector<long long> dist(V, LONG_MAX);
	pq.push({0, src});
	dist[src] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (auto nbr : adjList[u]) {
			int nbrNode = nbr.first;
			int nbrWt = nbr.second;
			if (dist[nbrNode] > dist[u] + nbrWt) {
				dist[nbrNode] = dist[u] + nbrWt;
				pq.push({dist[nbrNode], nbrNode});
			}
		}
	}
	for (int i = 0; i < V; i++)
		cout << i << " " << dist[i] << endl;
}

int main() {
	cin >> V >> E;
	adjList.resize(V);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addEdge(u, v, w);
	}
	dijkstra();
	return 0;
}
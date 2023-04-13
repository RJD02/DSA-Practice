#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adjList;
unordered_map<int, bool> visited;
void addEdge(int u, int v) {
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}
void bfs() {
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		cout << node << " ";
		vector<int> v;
		for (auto i : adjList[node]) {
			if (!visited[i]) {
				visited[i] = 1;
				v.push_back(i);
			}
		}
		sort(v.begin(), v.end());
		for (auto i : v) q.push(i);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int n, e;
	cin >> n >> e;
	if (n == 0) return 0;
	// Graph g;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	bfs();
	for (int i = 0; i < n; i++) if (!visited[i]) cout << i << " ";
	return 0;
}

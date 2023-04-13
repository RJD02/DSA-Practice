#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adjList;
unordered_map<int, bool> visited;
unordered_map<int, int> parent;

int v1, v2;

void addEdge(int u, int v) {
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

void bfs() {
	queue<int> q;
	q.push(v1);
	visited[v1] = true;
	while (!q.empty()) {
		int node = q.front(); q.pop();
		for (auto i : adjList[node]) {
			if (!visited[i]) {
				parent[i] = node;
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	cin >> v1 >> v2;
	parent[v1] = -1;
	bfs();
	int t = v2;
	if (visited[t]) {
		while (t != -1) {
			cout << t << " ";
			t = parent[t];
		}
	}
	return 0;
}
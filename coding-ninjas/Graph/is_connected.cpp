#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

vector<vector<int>> adjList(N);
vector<bool> visited(N);

void addEdge(int u, int v) {
	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

void bfs() {
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int node = q.front(); q.pop();
		for (auto i : adjList[node]) {
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		addEdge(u, v);
	}
	bfs();
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			ok = false;
			break;
		}
	}
	cout << (ok ? "true" : "false");
	return 0;
}
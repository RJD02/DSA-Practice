#include <bits/stdc++.h>
using namespace std;

const int N = 1001;

vector<vector<int>> adjList(N);
vector<bool> visited(N);

void bfs(int src) {
	queue<int> q;
	q.push(src);
	visited[src] = true;
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
	int count = 0;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			bfs(i);
			count++;
		}
	}
	cout << count;
	return 0;
}
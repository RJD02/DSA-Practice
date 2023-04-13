#include <bits/stdc++.h>
using namespace std;

int n, e;
const int N = 101;
vector<vector<int>> adjList(N);
// vector<int> parent(N, -1);
int countCycle = 0;
vector<bool> visited(N, false);
vector<int> parent(N, -1);
void dfs(int src = 0, int parent = -1) {
	for (auto i : adjList[src]) {
		if (i == parent) {
			countCycle++;
		}
		else if (!visited[i]) {
			visited[i] = true;
			dfs(i, src);
		}
	}
}

void bfs() {
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto i : adjList[node]) {
			if (i == node) continue;
			for (auto j : adjList[i]) {
				if (j == i) continue;
				for (auto k : adjList[j]) {
					if (k == node) countCycle++;
				}
			}
			if (!visited[i]) {
				visited[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> n >> e;
	if (n == 0 or e == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	bfs();
	cout << countCycle / 6;
	return 0;
}
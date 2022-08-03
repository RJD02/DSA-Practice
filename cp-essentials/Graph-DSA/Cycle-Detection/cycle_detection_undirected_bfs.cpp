#include <bits/stdc++.h>
using namespace std;

bool solve(int n, vector<vector<int>> edges) {
	vector<vector<int>> adjList(n + 1);

	for (auto i : edges) {
		adjList[i[0]].push_back(i[1]);
		adjList[i[1]].push_back(i[0]);
	}

	auto bfs = [&] (int source = 1) {
		queue<int> q;
		bool visited[n + 1];
		int parent[n + 1];

		q.push(source);
		visited[source] = 1;
		parent[source] = -1;
		while (!q.empty()) {
			int node = q.front(); q.pop();
			for (auto nbr : adjList[node]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = node;
				} else if (nbr != parent[node])
					return true;
			}
		}
		return false;
	};


	return bfs();
}

int main() {
	int n = 4;
	vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}, {3, 4}, {2, 4}};
	cout << solve(n, edges) << endl;
	return 0;
}
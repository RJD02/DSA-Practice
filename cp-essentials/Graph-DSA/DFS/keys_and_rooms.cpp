#include <bits/stdc++.h>
using namespace std;

void dfs(int node, bool *visited, vector<vector<int>> rooms) {
	visited[node] = true;
	for (int nbr : rooms[node]) {
		if (!visited[nbr])
			dfs(nbr, visited, rooms);
	}
}

bool canVisitAllRooms(vector<vector<int>> rooms) {
	int n = rooms.size();

	auto bfs = [&] (int source) {
		queue<int> q;
		vector<bool> visited(n);
		q.push(source);
		visited[source] = 1;

		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (auto i : rooms[node]) {
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
				}
			}
		}
		for (auto i : visited)
			if (i == false)
				return false;
		return true;
	};

	return bfs(0);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> rooms(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		// cout << a << " " << b << endl;
		rooms[a].push_back(b);
		rooms[b].push_back(a);
	}

	// for(auto i: rooms) {
	// 	for(auto j: i) {
	// 		cout << j << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << canVisitAllRooms(rooms);
	return 0;
}
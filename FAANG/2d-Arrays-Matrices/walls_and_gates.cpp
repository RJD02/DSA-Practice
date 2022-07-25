#include <bits/stdc++.h>
using namespace std;

void wallsAndGates(vector<vector<int>> &rooms) {
	int n = rooms.size(), m = rooms[0].size();
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (rooms[i][j] == 0)
				q.push({i, j});
		}
	}

	auto isInside = [=](int i, int j) {
		return i >= 0 and i < n and j >= 0 and j < m;
	};

	vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	int level = 1;
	int count = q.size();
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		count--;

		for (auto [dx, dy] : directions) {
			int i = x + dx, j = y + dy;
			if (isInside(i, j) and rooms[i][j] >= INT_MAX) {
				rooms[i][j] = level;
				q.push({i, j});
			}
		}

		if (count == 0) {
			count = q.size();
			level++;
		}
	}
}
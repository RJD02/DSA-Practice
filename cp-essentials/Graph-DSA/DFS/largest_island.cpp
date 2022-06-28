#include <bits/stdc++.h>
using namespace std;

int maxAreaOfIsland(vector<vector<int>> grid) {
	int n = grid.size();
	int m = grid[0].size();

	vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

	auto isInside = [=] (int x, int y) {
		return x < n and y < m and x >= 0 and y >= 0;
	};

	auto bfs = [&] (int i, int j) {
		int count = 0;
		queue<pair<int, int>> q;
		q.push({i, j});
		vector<bool> visited(n);

		while(!q.empty()) {
			auto [x, y] = q.front(); q.pop();
			count++;

			for(auto [dx, dy]: directions) {
				int xx = x + dx, yy = y + dy;
				if(isInside(xx, yy) and grid[xx][yy] == 1) {
					grid[xx][yy] = 0;
					q.push({xx, yy});
				}
			}
		}
		return count - 1;
	};

	int c = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 1)
				c = max(bfs(i, j), c);
		}
	}

	return c;
}
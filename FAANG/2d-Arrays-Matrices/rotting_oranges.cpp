#include <bits/stdc++.h>
using namespace std;

int orangeRotting(vector<vector<int>> &grid) {
	queue<pair<int, int>> q;
	int freshOranges = 0;
	int n = grid.size(), m = grid[0].size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 2)
				q.push({i, j});
			if(grid[i][j] == 1)
				freshOranges++;
		}
	}

	vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	auto isInside = [=] (int i, int j) {
		return i >= 0 and i < n and j >= 0 and j < m;
	};

	int count = q.size();
	int mins = -1;
	while(!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		count--;
		for(auto [dx, dy]: directions) {
			int i = x = dx, j = y + dy;
			if(isInside(i, j) and grid[i][j] == 1) {
				grid[i][j] = 2;
				q.push({i, j});
				freshOranges--;
			}
		}
		if(count == 0) {
			count = q.size();
			mins++;
		}
	}
	if(freshOranges > 0)
		return -1;
	return max(mins, 0);
}
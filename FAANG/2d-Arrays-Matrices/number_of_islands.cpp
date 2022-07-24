#include <bits/stdc++.h>
using namespace std;

std::vector<pair<int, int>> d4 = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));
	int size = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	auto isInside = [=] (int i, int j) {
		return i < n and i >= 0 and j < m and j >= 0;
	};

	auto bfs = [&](int i, int j) {
		size++;
		queue<pair<int, int>> q;
		q.push({i, j});
		while(!q.empty()) {
			auto [x, y] = q.front(); q.pop();
			for(auto [dx, dy]: d4) {
				int ii = x + dx, jj = y + dy;
				if(isInside(ii, jj) and grid[ii][jj] == 1 ) {
					q.push({ii, jj});
					grid[ii][jj] = 0;
				}
			}
		}
	};

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(grid[i][j] == 1)
				bfs(i, j);
		}
	}

	cout << size << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
	solve();
	return 0;
}
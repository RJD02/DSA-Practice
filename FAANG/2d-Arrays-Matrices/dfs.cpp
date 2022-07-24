#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> sides = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isInside(int i, int j, int n) {
	return i >= 0 and i < n and j >= 0 and j < n;
}

void dfs(vector<vector<int>> matrix, vector<vector<bool>>& visited, int i, int j) {
	visited[i][j] = true;
	cout << matrix[i][j] << " ";
	for (auto [x, y] : sides) {
		int ii = i + x, jj = j + y;
		if (isInside(ii, jj, matrix.size()) and !visited[ii][jj]  )
			dfs(matrix, visited, ii, jj);
	}
}

void bfs(vector<vector<int>> matrix) {
	int n = matrix.size();
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	visited[0][0] = true;
	q.push({0, 0});
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for(auto [dx, dy] : sides) {
			int i = x + dx, j = y + dy;
			if(isInside(i, j, n) and !visited[i][j]) {
				visited[i][j] = true;
				q.push({i, j});
			}

		}
		cout << matrix[x][y] << " ";
	}
}

int main() {
	// std::ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));
	int ind = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			grid[i][j] = ind++;
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	// dfs(grid, visited, 0, 0);
	bfs(grid);
	return 0;
}
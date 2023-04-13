#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<bool>> visited;
vector<vector<int>> matrix;

int bfs(int i, int j) {
	int val = 0;
	queue<pair<int, int>> q;
	int curr = matrix[i][j];
	int n = matrix.size();
	visited[i][j] = true;
	q.push({i, j});
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (auto d : directions) {
			int xx = x + d.first, yy = y + d.second;
			if (xx >= 0 and xx < n and yy >= 0 and yy < n and !visited[xx][yy] and matrix[xx][yy] == curr) {
				q.push({xx, yy});
				visited[xx][yy] = true;
				val++;
			}
		}
	}
	return val + 1;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
	visited.resize(n, vector<bool>(n));
	matrix = cake;
	int maxVal = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] and matrix[i][j] == 1)
				maxVal = max(maxVal, bfs(i, j));
		}
	}
	return maxVal;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> cake(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> cake[i][j];
		}
	}

	cout << getBiggestPieceSize(cake, n);
}
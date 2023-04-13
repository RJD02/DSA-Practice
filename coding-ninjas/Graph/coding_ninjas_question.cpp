#include <bits/stdc++.h>
using namespace std;

string key = "CODINGNINJA";

vector<pair<int, int>> directions = {{ -1, 0}, { -1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, { -1, -1}};

vector<vector<char>> matrix;
vector<vector<bool>> visited;

bool dfs(int i, int j, int idx = 0) {
	if (visited[i][j]) return false;
	visited[i][j] = true;
	if (idx == key.size()) return true;
	int n = matrix.size(), m = matrix[0].size();
	bool ok = false;
	for (auto d : directions) {
		int x = i + d.first, y = j + d.second;
		if (x >= 0 and x < n and y >= 0 and y < m) {
			// cout << matrix[x][y] << " " << key[idx] << "\n";
			if (idx < key.size() and matrix[x][y] == key[idx]) {
				ok |= dfs(x, y, idx + 1);
				// idx++;
			}
		}
	}
	return ok;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
	matrix = board;
	visited.resize(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == key[0]) {
				int idx = 1;
				if (dfs(i, j, idx)) return true;
				visited.resize(n, vector<bool>(m, false));
			}
		}
	}
	return false;
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> board(n, vector<char>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	cout << (hasPath(board, n, m) ? 1 : 0);
}
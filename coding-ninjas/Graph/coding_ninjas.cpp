#include <bits/stdc++.h>
using namespace std;

string key = "CODINGNINJA";
vector<string> matrix;
int idx = 0;

vector<pair<int, int>> directions = {{ -1, 0}, { -1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, { -1, -1}};
vector<vector<bool>> visited;
void dfs(int i, int j) {
	if (!visited[i][j]) {
		visited[i][j] = true;
		for (auto d : directions) {
			int x = d.first + i, y = d.second + j;
			if (x >= 0 and x < matrix.size() and y >= 0 and y < matrix[0].size()) {
				if (key[idx] == matrix[x][y]) {
					idx++;
					dfs(x, y);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	matrix.resize(n);
	visited.resize(n, vector<bool>(m));
	for (int i = 0; i < n; i++) cin >> matrix[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 'C') {
				idx = 1;
				dfs(i, j);
				if (idx == key.size()) {
					cout << 1;
					return 0;
				}
			}
		}
	}

	cout << 0;
	return 0;
}
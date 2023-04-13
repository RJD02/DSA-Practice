#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> visited;
vector<vector<char>> matrix;
vector<pair<int, int>> directions = {{ -1, 0}, { -1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, { -1, -1}};
bool dfs(int i, int j, int k) {
    if (k >= 4) return true;
    if (visited[i][j]) return false;
    visited[i][j] = true;
    int n = matrix.size(), m = matrix[0].size();
    bool ok = false;
    for (auto d : directions) {
        int x = d.first + i, y = d.second + j;
        if (x >= 0 and x < n and y >= 0 and y < m) {
            // it is inside
            if (matrix[x][y] == matrix[i][j]) {
                ok |= dfs(x, y, k + 1);
            }
        }
    }
    return ok;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    visited.resize(n, vector<bool>(m));
    matrix = board;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dfs(i, j, 0)) {
                return true;
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

    cout << (hasCycle(board, n, m) ? "true" : "false");
}
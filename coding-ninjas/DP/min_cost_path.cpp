#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n) {
	vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {1, 1}};
	queue<vector<int>> q;
	q.push({0, 0, input[0][0]});
	int minVal = INT_MAX;
	while (!q.empty()) {
		auto curr = q.front(); q.pop();
		if (curr[0] == m - 1 and curr[1] == n - 1) minVal = min(minVal, curr[2]);
		for (auto i : directions) {
			int x = curr[0] + i.first, y = curr[1] + i.second;
			if (x >= 0 and x < m and y >= 0 and y < n) {
				q.push({x, y, input[x][y] + curr[2]});
			}
		}
	}
	return minVal;
}


int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{ -2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

// TLE
double knightProbabilityBruteForce(int n, int k, int row, int col) {
	// withing the boundaries?
	if(row < 0 or col < 0 or row >= n or col >= n)
		return 0;
	if(k == 0)
		return 1;
	double res = 0;
	for(auto [x, y]: directions) {
		res += knightProbabilityBruteForce(n, k - 1, row + x, col + y) / 8.0;
	}
	return res;
}
// T: O(k * n ^ 2)
// S: O(k * n ^ 2)
double recurse(int n, int k, int r, int c, vector<vector<vector<int>>> &dp) {
	if(r < 0 or r >= n or c < 0 or c >= n)
		return 0;
	if(k == 0)
		return 1;
	if(dp[k][r][c] != -1)
		return dp[k][r][c];
	double res = 0;
	for(auto [x, y]: directions) {
		res += recurse(n, k, r + x, c + y, dp) / 8.0;
	}
	dp[k][r][c] = res;
	return dp[k][r][c];
}

double knightProbabilityMemoizing(int n, int k, int r, int c) {
	vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(n, vector<int>(n, -1)));
	// for(auto i: dp) {
	// 	for(auto j: i) {
	// 		for(auto l: j)
	// 			cout << l << " ";
	// 		cout << endl;
	// 	}
	// 	cout << endl; 
	// }
	return recurse(n, k, r, c, dp);
}

int main() {
	int n, row, column, k;
	cin >> n >> k >> row >> column;
	cout << knightProbabilityMemoizing(n, k, row, column);
	return 0;
}
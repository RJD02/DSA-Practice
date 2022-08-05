#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int dp[n + 1];
	dp[0] = 0;
	dp[1] = 0;
	for(int i = 2; i <= n; i++) {
		int minus_one = dp[i - 1];
		int divide_by_2 = i % 2 == 0 ? dp[i / 2] : INT_MAX;
		int divide_by_3 = i % 3 == 0 ? dp[i / 3] : INT_MAX;
		dp[i] = min(minus_one, min(divide_by_2, divide_by_3)) + 1;
	}
	cout << dp[n] << endl;
}

int main() {
	solve();
	return 0;
}
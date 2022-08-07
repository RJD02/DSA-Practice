#include <bits/stdc++.h>
using namespace std;

int dp[31];

void solve(int t) {
	if (t % 2 == 1)
		cout << 0 << endl;
	else if (dp[t] != 0)
		cout << dp[t] << endl;
	else {
		for (int i = 4; i <= t; i++)
			dp[i] = 4 * dp[i - 2] - dp[i - 4];
		cout << dp[t] << endl;
	}
}

int main() {
	memset(dp, 0, sizeof dp);
	int t;
	cin >> t;
	dp[0] = 1; dp[2] = 3;
	while (t != -1) {
		solve(t);
		cin >> t;
	}
	return 0;
}
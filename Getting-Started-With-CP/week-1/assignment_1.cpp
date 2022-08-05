
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int

using namespace std;

ll dp[10005];

void solve() {
	ll n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 3;
	for(int i = 4; i <= n; i++) {
		int first = i / 2;
		int second = (i + 1) / 2;
		dp[i] = first * second + dp[first] + dp[second];
	}
	cout << dp[n] << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}
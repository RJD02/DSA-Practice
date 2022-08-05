#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve() {
	string s;
	cin >> s;
	while(s != "0") {
		int n = s.size();
		int dp[n];
		dp[n - 1] = 1;
		for(int i = n - 3; i >= 0; i--) {
			int temp = (s[i + 1] - '0') * 10 + s[i + 2] - '0';
			dp[i] = dp[i + 1];
			if(temp >= 1 and temp <= 26) {
				dp[i] += dp[i + 2];
				// cout << temp << endl;
			}
		}
		cout << dp[0] << endl;
		cin >> s;
	}
}

int main() {
	solve();
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dp[1000000];

// -1 = untouched
// 0  = false
// 1  = true

bool isMagicNumberDP(int n) {
	if(dp[n] == 1)
		return true;
	if(dp[n] == 0)
		return false;
	if(n == 1)
		return true;
	if(n / 10 == 0) 
		return dp[n] = 0;
	int sum = 0;
	int num = n;
	while(n) {
		int rem = n % 10;
		rem = rem * rem;
		sum += rem;
		n /= 10;
	}
	return isMagicNumberDP(sum);
}

bool isMagicNumber(int n) {
	if(n == 1)
		return true;
	if(n / 10 == 0)
		return false;
	int sum = 0;
	while(n) {
		int rem = n % 10;
		rem = rem * rem;
		sum += rem;
		n /= 10;
	}
	return isMagicNumber(sum);
}

void solve() {
	int n;
	cin >> n;
	cout << isMagicNumber(n) << " " << isMagicNumberDP(n) << endl;
}

int main() {
	memset(dp, -1, sizeof dp);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
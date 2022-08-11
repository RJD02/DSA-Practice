#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll> memo;
string s;

ll dp(ll i) {
	if(i == s.size()) return 1;
	if(memo[i] != -1) return memo[i];
	int ans = 0;
	if(s[i] >= '1' and s[i] <= '9')
		ans += dp(i + 1);
	if(i + 1 < s.size() and s[i] == '1')
		ans += dp(i + 2);
	if(i + 1 < s.size() and s[i] == '2' and s[i] <= '6')
		ans += dp(i + 2);
	return memo[i] = ans;
}

int main() {
	cin >> s;
	while (s != "0") {
		memo.clear();
		memo.resize(s.size(), -1);
		cout << dp(0) << endl;
		cin >> s;
	}
}
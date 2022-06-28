
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
// #define debug()

using namespace std;

void solve() {
	string s, t;
	cin >> s >> t;
	if(s.size() == t.size()) {
		if(s == t)
			cout << s << endl;
		else
			cout << -1 << endl;
		return ;
	}
	if(s.size() > t.size())
		swap(s, t);
	int n = s.size();
	int m = t.size();
	int lcm = (n * m) / __gcd(n, m);
	string ans = "";
	int k = 0;
	for(int i = 0; i < lcm; i++) {
		ans += (char)s[k];
		k++;
		k %= n; /* ! killer move.. It sets the count of k back to 0 if k exceeds n i.e. size of smaller string */
	}
	k = 0;
	for (int i = 0; i < lcm; ++i) {
		if(ans[i] != t[k]) {
			cout << -1 << endl;
			return ;
		}
		k++;
		k %= m; /* Once again killer move/logic */
	}
	cout << ans << endl;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		solve();
	}
	return 0;
}

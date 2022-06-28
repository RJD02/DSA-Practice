
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

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	std::vector<int> a(n + 1);
	for (int i = 1; i < k + 1; ++i) {
		a[i] = i;
	}
	int x = k - 1;
	for (int i = k + 1; i < n + 1; ++i)	{
		a[i] = x--;
	}
	vi b(k + 1);
	vi ans;
	for (int i = n; i >= 1; --i) {
		if(b[a[i]] == 1)
			continue;
		else {
			ans.push_back(a[i]);
			b[a[i]] = 1;
		}
	}
	reverse(all(ans));
	for(auto i : ans)
		cout << i <<  " ";
	cout << endl;
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

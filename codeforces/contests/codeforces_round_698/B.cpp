
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
	int q, d;
	cin >> q >> d;
	std::vector<int> v(q);
	for(int i = 0;i < q; i++)
		cin >> v[i];
	for(int i = 0; i < q; i++) {
		if(v[i] < 7)
			cout << "NO\n";
		else if(v[i] % 10 == 7)
			cout << "YES\n";
		else if(v[i] % 7 != 4)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
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

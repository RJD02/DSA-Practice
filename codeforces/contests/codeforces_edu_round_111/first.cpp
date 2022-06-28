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
#define pb push_back
#define pf pop_back
using namespace std;

void solve() {
	int n;
	cin >> n;
	if(n == 1) {
		cout << 1 << endl;
		return ;
	}
	for(int i = 2; i < n / 2; i++) {
		if(n % i == 0 || n % i - 1 == 0 || n % i - 2 == 0) {
			cout << i << endl;
			return ;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	//Try till the end!!
	//Don't give up
	//Goal: A, B, C
	while (T--)
	{
		solve();
	}
	return 0;
}

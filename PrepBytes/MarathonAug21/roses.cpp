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
#define rep(i, m, n) for (auto i = m; i != n; i++)
#define um(x, y) unordered_map<x, y>
#define us(x) unordered_set<x>
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
	int count = 0;
	if(n >= 100) {
		count += n / 100;
		n %= 100;
	}
	if(n >= 20) {
		count += n / 20;
		n %= 20;
	}
	if(n >= 10) {
		count += n / 10;
		n %= 10;
	}
	if(n >= 5) {
		count += n / 5;
		n %= 5;
	}
	cout << count + n << endl;
}

int main()
{
//#ifndef ONLINE_JUDGE
////For getting input from input.txt
//freopen("input.txt", "r", stdin);
////For writing output to output.txt
//freopen("output.txt", "w", stdout);
//#endif //ONLINE_JUDGE
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	//Try till the end!!
	//Don't give up
	//Goal: A, B, C
	while(T--)
	{
		solve();
	}
	return 0;
}

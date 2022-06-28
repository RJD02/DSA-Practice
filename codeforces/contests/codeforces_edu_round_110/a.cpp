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
	std::vector<int> v(4);
	int strong1, strong2;
	strong1 = strong2 = 0;
	for(int i = 0; i < 4; i++) {
		cin >> v[i];
	}
	int f1 = v[0] > v[1] ? v[0] : v[1];
	int f2 = v[2] > v[3] ? v[2] : v[3];
	// cout << strong1 << " " << strong2 << endl;
	// cout << f1 << " " << f2 << endl;
	sort(v.begin(), v.end());
	if((f1 == v[3] && f2 == v[2]) || (f2 == v[3] && f1 == v[2]))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
#ifndef ONLINE_JUDGE
//For getting input from input.txt
freopen("input.txt", "r", stdin);
//For writing output to output.txt
freopen("output.txt", "w", stdout);
#endif //ONLINE_JUDGE
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

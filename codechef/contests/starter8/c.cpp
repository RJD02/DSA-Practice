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
#define x first
#define y second
#define pb push_back
#define pf pop_back
#define debug(i, j) cout << "{" << i << "," << j << "} "
using namespace std;

void solve() {
	pair<ll, ll> a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	if((a.x == b.x || b.x == c.x) && (a.y == b.y || b.y == c.y)) {
		cout << "YES";
	}
	// else if(a.y == b.y && b.x == c.x) {
	// 	cout << "YES";
	// }
	// else if(a.x == b.x && b.y == c.y) {
	// 	cout << "YES";
	// }
	else if((b.x == c.x || b.y == c.y) && (a.x == b.x || a.y == b.y)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	cout << endl;

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

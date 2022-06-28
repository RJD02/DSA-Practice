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
#define debug(i, j) cout << "{" << i << "," << j << "} "
using namespace std;

void solve() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<pair<int, int>> v(n);
	vi res;
	int count = 0;
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v[i] = (mp(k, i + 1));
	}
	sort(all(v));
	// for(auto i : v)
	// 	cout << (i).f << " ";
	// cout << endl;
	for(int i = v.size() - 1; i >= 0; i--) {
		if(v[i].f >= m) {
			count++;
			res.eb(v[i].s);
		}
	}
	x -= count;
	for(int i = v.size() - 1 - count; i >= 0 && x > 0; i--) {
		res.eb(v[i].s);
		--x;
	}
	sort(all(res));
	cout << res.size() << " ";
	for(int i : res) {
		cout << i << " ";
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

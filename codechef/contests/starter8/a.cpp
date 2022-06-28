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
	vi v(10);
	int odd = 0, even = 0, turn = 0;
	for(int i = 0; i < 10; i++) {
		int k;
		cin >> k;
		if(turn == 0) {
			even += k;
			turn = 1;
		} else {
			odd += k;
			turn = 0;
		}
	}
	if(even == odd) {
		cout << 0;
	}
	else if(even > odd) {
		cout << 1;
	} else {
		cout << 2;
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

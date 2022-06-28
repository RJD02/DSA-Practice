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
	vi v(n);
	float res = 0;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		res += v[i];
	}
	float avg = res / v.size();
	if(ceilf(avg) == avg && avg == 1) {
		cout << 1 << endl;
		return ;
	}
	cout << abs(n - avg) << endl;
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
		cout << "CASE #" << T << " : ";
		solve();
	}
	return 0;
}

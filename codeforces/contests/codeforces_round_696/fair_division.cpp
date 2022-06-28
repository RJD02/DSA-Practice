
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
	int n;
	cin >> n;
	std::vector<int> c(n);
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> c[i];
		sum += c[i];
	}
	if(sum % 2 != 0) {
		cout << "NO" << endl;
		return ;
	}
	int count1 = 0, count2 = 0;
	for(int i = 0; i < n; i++)
		if(c[i] == 1)
			count1++;
		else
			count2++;
	// if(count1 == 0 && count2 % 2 == 0)
	// 	cout << "YES" << endl;
	if(count1 == 0 && n % 2 == 0) {
		cout << "YES\n";
		return ;
	}
	if(sum % 2 == 0 && count1 >= 2) {
		cout << "YES\n";
		return ;
	}
	cout << "NO\n";
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

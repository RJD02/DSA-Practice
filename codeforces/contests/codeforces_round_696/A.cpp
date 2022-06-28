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
	string b;
	string a;
	cin >> b;
	string c;
	// a.append((char)((int)b[0] + 1));
	// a.push_back((char)((int)(b[0]) + 1));
	c.push_back('1');
	for(int i = 0;i + 1 < n; i++) {
		if(b[i] != b[i + 1] || (c[i] == '0' && b[i] != '1')) {
			// a.append((char)((int)b[i] + 1));
			// a.push_back((char)((int)b[i] + 1));
			c.push_back('1');
			// b[i+1] = '0';
		}
		else
			c.push_back('0');
			// a.push_back((char)((int)b[i] + 0));
			// a.append((char)((int)b[i] + 0));
	}
	cout << c << endl;
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

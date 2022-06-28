
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

void inline swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int nod(int n) {
	int count = 0;
	while(n) {
		count++;
		n /= 10;
	}
	return count;
}

void solve() {
	// int n;
	// cin >> n;
	int n, k;
	cin >> n >> k;
	if(n == 1) {
		cout << k << endl;
		return ;
	}
	if(n < k)
		swap(&n, &k);
	int num = nod(n);
	cout << n % k + num << endl;
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

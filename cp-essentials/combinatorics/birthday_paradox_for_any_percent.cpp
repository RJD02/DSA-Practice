#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl			"\n"
#define ll 				long long int
#define vi 				vector<int>
#define vll				vector<ll>
#define vvi 			vector < vi >
#define vb 				vector<bool>
#define vs 				vector<string>
#define pii 			pair<int,int>
#define pll 			pair<long long, long long>
#define vpi				vector <pii>
#define vpp 			vector<pair<ll,ll>>
#define mii				map <int, int>
#define mpi 			map <pii, int>
#define spi 			set <pii>
#define que_max			priority_queue <int>
#define que_min			priority_queue <int, vi, greater<int>>
#define repi(i, m, n) 	for (auto i = m; i != n; i++)
#define repd(i, m, n) 	for(auto i = m; i != n; i--)
#define FOR(i, a, b) 	for (ll i = a; i <= b; i++)
#define RFOR(i, a, b) 	for (ll i = a; i >= b; i--)
#define FOREACH(a, b) 	for (auto&(a) : (b)) 
#define um(x, y) 		unordered_map<x, y>
#define us(x) 			unordered_set<x>
#define om(x, y)		map<x, y>
#define os(x)			set<x>
#define mod 			1000000007
#define inf 			1000000000000000001;
#define all(c) 			c.begin(),c.end()
#define rall(v) 		v.rbegin(), v.rend()
#define mp(x,y) 		make_pair(x,y)
#define mem(a,val) 		memset(a,val,sizeof(a))
#define sz(x) 			x.size()
#define eb 				emplace_back
#define f 				first
#define s 				second
#define pb 				push_back
#define pf 				pop_back
#define prec(n) 		fixed<<setprecision(n)
#define bit(n, i) 		(n & (1 << i))
#define bug(...)		__f (#__VA_ARGS__, __VA_ARGS__)
#define debug(i, j) 	cout << "{" << i << "," << j << "} "
#define min3(a, b, c) 	min(a, min(b, c))
#define max3(a, b, c) 	max(a, max(b, c))
#define maxArr(a,n) 	*max_element(a,a+n)
#define minArr(a,n) 	*min_element(a,a+n)
#define maxVec(a) 		*max_element(a.begin(), a.end())
#define minVec(a) 		*min_element(a.begin(), a.end())
#define present(c, x)	((c).find(x) != (c).end()) 
#define cpresent(c, x)	(find(all((c)), (x)) != (c).end())
#define print1(a)		for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)	for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

using namespace std;
using namespace std::chrono;

/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
template<typename T> T logAToBaseB(T a, T b) {
	return a > b - 1 ? 1 + logAToBaseB(a / b, b) : 0;
}
template<typename T> T logAToBaseBDec(T a, T b) {
	return log(a) / log(b);
}
template<typename T> T numberOfDigits(T a) {
	return (int)floor(1 + logAToBaseBDec(a, 10));
}
template<typename T> double nthRoot(T a, T b) {
	double xPre = rand() % 10;
	double eps = 1e-3;
	double delX = INT_MAX;
	double xK;
	while (delX > eps) {
		xK = ((b - 1.0) * xPre + (double)a / pow(xPre, b - 1)) / (double)b;
		delX = abs(xK - xPre);
		xPre = xK;
	}
	return xK;
}
template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
/**********************************************/

inline ll lcm(ll a, ll b) {return (a*b)/__gcd(a,b);}
inline int intlcm(int a, int b) {return (a*b)/__gcd(a,b);}
inline int intpow(int a, int b) {return (int)(pow(a,b) + 0.5);}
inline ll llpow(ll a, ll b) {return (ll)(pow(a,b) + 0.5);}

float prob(ll people) {
	double total = 1;
	for (ll i = 0; i < people; i++) {
		total *= (365 - i) / 365.0;
	}
	return total;
}

void solve() {
	float p = 0;
	float one_p = 1.0;
	ll people = 1;
	float percent;
	cin >> percent;
	while (one_p > 1 - percent) {
		one_p = prob(people);
		// bug(one_p, p, people);
		people++;
	}
	p = 1 - one_p;
	if (people > 1) people--;
	cout << people << " " << p << " " << one_p;
}

int main() {
	//#ifndef ONLINE_JUDGE
	//For getting input from input.txt
	//freopen("input.txt", "r", stdin);
	//For writing output to output.txt
	//freopen("output.txt", "w", stdout);
	//#endif //ONLINE_JUDGE
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	auto start = high_resolution_clock::now();
	int T = 1;
	// cin >> T;
	// cin.ignore(); must be there when using getline(cin, s)
	// Flashy Wally, never forget the gifted improvisor
	// HiToMizu, flow and power. 12th sign can be all of the elements
	// Backed by the largest and the farthest planets, and sun is in your name
	// Remember, you are loved and your obsession is to be better, not perfect. Go get it.
	while(T--) solve();

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cerr << "Run Time : " << duration.count() << "ms";

	return 0;
}


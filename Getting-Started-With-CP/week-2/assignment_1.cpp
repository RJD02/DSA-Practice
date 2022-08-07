#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, x; cin >> n >> x;
	vector<int> v(2 * n);
	for(int i = 0; i < 2 * n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	bool ok = true;
	for(int i = n; i < 2 * n; i++) {
		if(v[i] < v[i - n] + x) {
			ok = false;
			break;
		}
	}
	ok ? cout << "YES" : cout << "NO";
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
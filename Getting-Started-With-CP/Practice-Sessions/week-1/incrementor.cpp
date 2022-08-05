#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int minVal = INT_MAX, maxVal = -INT_MAX;
	for(int i = 0; i < n; i++) {
		int in; cin >> in;
		minVal = min(minVal, in);
		maxVal = max(maxVal, in);
	}
	cout << abs(minVal - maxVal) << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
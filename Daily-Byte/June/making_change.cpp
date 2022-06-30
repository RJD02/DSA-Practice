/*
This question is asked by Facebook. Given an array that represents different coin denominations and an amount of change you need to make, return the fewest number of coins it takes to make the given amount of change.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, amt;
	cin >> n >> amt;
	vector<int> coins(n);
	for(int i = 0; i < n; i++)
		cin >> coins[i];
	sort(coins.begin(), coins.end(), greater<int>());
	int count = 0;
	// for(auto a: coins) {
	// 	cout << a << " ";
	// }
	// cout << endl;

	for(int i = 0; i < n; i++) {
		count += amt / coins[i];
		amt = amt % coins[i];
	}
	cout << count << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) 
		solve();
	return 0;
}
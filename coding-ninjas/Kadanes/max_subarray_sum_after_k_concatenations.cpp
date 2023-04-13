#include <bits/stdc++.h>
using namespace std;

long long maxSubSumKConcat(vector<int> &arr, int n, int k) {
	vector<int> b(arr.begin(), arr.end());
	for(int i = 1; i < k; i++)
		arr.insert(arr.end(), b.begin(), b.end());
	// for(auto i: arr)
	// 	cout << i << " ";
	// cout << endl;
	long long currSum = 0, maxSum = -INT_MAX;
	for(auto i: arr) {
		cout << i << " ";
		currSum += i;
		maxSum = max(maxSum, currSum);
		currSum = max(currSum, (long long)0);
	}
	cout << endl;
	return maxSum;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	cout << maxSubSumKConcat(v, n, k) << endl;
}

int main() {
	int tc;
	cin >> tc;
	while(tc--) solve();
}
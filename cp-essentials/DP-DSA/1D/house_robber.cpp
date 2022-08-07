#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> nums) {
	if (nums.size() < 2)
		return nums[0];
	int n = nums.size();
	int dp[n + 1];
	dp[0] = nums[0];
	dp[1] = max(nums[1], dp[0]);

	for (int i = 2; i < n; i++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
	}
	return dp[n - 1];
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << rob(v) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
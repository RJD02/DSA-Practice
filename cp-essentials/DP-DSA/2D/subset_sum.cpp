#include <bits/stdc++.h>
using namespace std;


bool subsetSumExists(int index, vector<int> v, int sum, vector<vector<int>> &memo) {
	if(index == -1)
		return (sum == 0);
	if(memo[index][sum] != -1)
		return memo[index][sum];
	bool ans = false;
	if(sum >= v[index])
		ans |= subsetSumExists(index - 1, v, sum - v[index], memo);
	ans |= subsetSumExists(index - 1, v, sum, memo);
	return (memo[index][sum] = ans);
}

void solve() {
	int n, sum;
	cin >> n >> sum;
	vector<int> v(n);
	vector<vector<int>> memo(n, vector<int>(sum, -1));
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << !subsetSumExists(n - 1, v, sum, memo) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
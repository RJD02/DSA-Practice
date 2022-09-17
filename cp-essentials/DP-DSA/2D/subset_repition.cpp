#include <bits/stdc++.h>
using namespace std;
// There shouldn't be any 0
bool subsetSum(int index, int sum, vector<int> &v, vector<vector<int>> &memo) {
	if(index == -1)
		return (sum == 0);
	bool ans = false;
	if(memo[index][sum] != -1)
		return memo[index][sum];
	if(sum >= v[index]) {
		ans |= subsetSum(index, sum - v[index], v, memo);
	}
	ans |= subsetSum(index - 1, sum, v, memo);
	memo[index][sum] = ans;
	return ans;
}

void solve() {

	int n, sum;
	cin >> n >> sum;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	vector<vector<int>> memo(n, vector<int>(sum, -1));
	cout << subsetSum(n - 1, sum, v, memo) << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
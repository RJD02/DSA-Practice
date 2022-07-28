/*
First step -> Figuring out recursive solution from recurrence relation
Second step -> Memoizing our redundant recursive calls
Third step -> Bottom Up tabulation
Fourth step -> Bottom Up optimization
*/

// Find minimum cost for climbing the stairs
#include <bits/stdc++.h>
using namespace std;


// T: O(2^n), S: O(n)
int minCostRecursive(int i, vector<int> cost) {
	if (i < 0)
		return 0;
	if(i <= 1)
		return cost[i];
	return cost[i] + min(minCostRecursive(i - 1, cost), minCostRecursive(i - 2, cost));
}

int minCostClimbingStairsRecursive(vector<int>& cost) {
	int n = cost.size();
	return min(minCostRecursive(n - 1, cost), minCostRecursive(n - 2, cost));
}

// T: O(n), S: O(n)
int minCostMemoization(int i, vector<int> cost, vector<int>& dp) {
	if(i < 0)
		return 0;
	if(i <= 1)
		return cost[i];
	if(dp[i] != INT_MAX)
		return dp[i];
	dp[i] = cost[i] + min(minCostMemoization(i - 1, cost, dp), minCostMemoization(i - 2, cost, dp));
}

int minCostClimbingStairsMemoization(vector<int> &cost) {
	int n = cost.size();
	vector<int> dp(n, INT_MAX);
	return min(minCostMemoization(n - 1, cost, dp), minCostMemoization(n - 2, cost, dp));
}

// T: O(n), S: O(n)
int minCostClimbingStairsBottomUp(vector<int> &cost) {
	int n = cost.size();
	vector<int> dp(n, INT_MAX);
	dp[0] = cost[0];
	dp[1] = cost[1];
	for(int i = 2; i < n; i++) {
		dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
	}
	return min(dp[n - 1], dp[n - 2]);
}

// T: O(n), S: O(1)
int minCostClimbingStairsOptimized(vector<int> &cost) {
	int n = cost.size();
	int pprev = cost[0], prev = cost[1];
	int curr = INT_MAX;
	for(int i = 2; i < n; i++) {
		curr = cost[i] + min(pprev, prev);
		pprev = prev;
		prev = curr;
	}
	return min(prev, pprev);
}
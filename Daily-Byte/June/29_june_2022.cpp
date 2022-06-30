// This question is asked by Apple.
// Given a staircase where the ith step has a non-negative
// cost associated with it given by cost[i],
// return the minimum cost of climbing to the top of
// the staircase. You may climb one or two steps at a time
// and you may start climbing from either the first or second step.

#include <bits/stdc++.h>
using namespace std;

int minCountClimbing(int i, vector<int> cost) {
	if (i == 0)
		return cost[0];
	if (i == 1)
		return cost[1];
	int cost1 = minCountClimbing(i - 1, cost) + cost[i];
	int cost2 = minCountClimbing(i - 2, cost) + cost[i];
	return min(cost1, cost2);
}

void solve() {
	int n;
	cin >> n;
	vector<int> cost(n + 1, 0);
	for (int i = 0; i < n; i++)
		cin >> cost[i];



	cout << minCountClimbing(n, cost) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t-- ) {
		solve();
	}
	return 0;
}

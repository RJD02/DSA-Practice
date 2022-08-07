#include <bits/stdc++.h>
using namespace std;

bool sumExists(int i, vector<int> v, int sum) {
	if(sum == 0)
		return true;
	if(i == v.size())
		return false;
	return sumExists(i + 1, v, sum - v[i]) + sumExists(i + 1, v, sum);
}

void solve() {
	int n, sum;
	cin >> n >> sum;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	cout << sumExists(0, v, sum) << endl;
}

int main() {
	int n;
	cin >> n;
	while(n--)
		solve();
	return 0;
}
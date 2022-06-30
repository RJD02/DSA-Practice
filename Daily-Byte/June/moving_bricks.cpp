/*
You are transporting bricks on a construction site and want to work as efficiently as possible. The weight of each brick is given by bricks[i]. Given a wheelbarrow that can carry up to (not including) 5000 pounds, return then maximum number of bricks you can place in your wheelbarrow to transport.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i =0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int currLoad = 0;
	int count = 0;
	for(auto i: v) {
		if(currLoad + i < 5000) {
			currLoad += i;
			count++;
		}
	}
	cout << count << endl;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
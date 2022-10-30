#include <bits/stdc++.h>
using namespace std;


int solve(vector<int> v) {
	int maxCount = 0;
	int n = v.size();

	for(int i = 0; i < n; i++) {
		int countPlus = 0, countMinus = 0, countSame = 0, maxCurr = 0;
		for(int j = i + 1; j < n; j++) { // O(n^2)
			if(v[i] + 1 == v[j])
				countPlus++;
			if(v[i] - 1 == v[j])
				countMinus++;
			if(v[i] == v[j])
				countSame++;
		}
		if(countPlus == 0 and countMinus == 0)
			countSame = 0;
		maxCurr = max(countPlus, countMinus) + countSame;
		maxCount = max(maxCount, maxCurr);
	}
	return maxCount > 0 ? maxCount + 1 : maxCount;
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	cout << solve(v);
	return 0;
}
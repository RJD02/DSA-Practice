#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
	int count = 0, maxCount = 0;
	while(n) {
		if((n & 1)) {
			count++;
			maxCount = max(maxCount, count);
		} else {
			count = 0;
		}
		n >>= 1;
	}
	return maxCount;
}
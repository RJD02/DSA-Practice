#include <bits/stdc++.h>
using namespace std;

bool isPowerOfFour(int n) {
	int m = sqrt(n);
	return (m & (m - 1)) == 0;
}
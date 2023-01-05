#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	bitset<32> b1(a), b2(b);
	int oneInA = b1.count(), oneInB = b2.count();
	if(oneInA == oneInB)
		return a < b;
	return oneInA < oneInB;
}

class Solution {
public:
	vector<int> sortByBits(vector<int> &arr) {
		sort(arr.begin(), arr.end(), cmp);
		return arr;
	}
};
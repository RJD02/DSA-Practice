#include <bits/stdc++.h>
using namespace std;

class Solution {
	int minSum(vector<int> a) {
		int avg = 0;
		for(auto i: a)
			avg += i;
		avg = avg / a.size() + 1;

		sort(a.begin(), a.end());
		int i = 0;
		while(a[i] == a[i + 1] and i < a.size()) {
			i++;
		}
		if(i + 1 >= a.size()) {
			return 0;
		}
		a[i] = a[i - 1] = avg;
		int highest = a[a.size() - 1] - a[i];
		int lowest = 0;
		return lowest + highest;
	}
};

int main() {
	;
}
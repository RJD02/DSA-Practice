#include <bits/stdc++.h>
using namespace std;

int convertToBin(int n) {
	int  p = 1, ans = 0;
	while(n) {
		ans += (n & 1) * p;
		p *= 10;
		n >>= 1;
	}
	return ans;
}


int main() {
	int n;
	cin >> n;
	cout << convertToBin(n);
	return 0;
}
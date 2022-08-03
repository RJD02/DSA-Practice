#include <bits/stdc++.h>
using namespace std;

int countBits(int n) {
	int count = 0;
	while(n) {
		if(n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}


int main() {
	int n;
	cin >> n;
	cout << countBits(n);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &a, int num, int &size) {
	int carry = 0;
	for(int i = 0; i < size; i++) {
		int product = num * a[i] + carry;
		carry = product / 10;
		a[i] = product % 10;
	}
	while(carry) {
		a[size++] = carry % 10;
		carry = carry / 10;
	}
}

void bigFactorial(int n) {
	std::vector<int> v(1000, 0);
	v[0] = 1;
	int size = 1;
	for(int i = 2; i <= n; i++) {
		multiply(v, i, size);
	}
	for(int i = size - 1; i >= 0; i--) {
		cout << v[i];
	}
}

int main() {
	int n;
	cin >> n;
	bigFactorial(n);
}

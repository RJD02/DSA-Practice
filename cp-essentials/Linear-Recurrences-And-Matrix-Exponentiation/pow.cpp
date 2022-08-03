#include <bits/stdc++.h>
using namespace std;

long long power(int a, int b) {
	long long res = 1;
	while(b) {
		if(b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

string solve(int a, int b, int c) {
	long long ac = power(a, c);
	long long bc = power(b, c);
	if(ac < bc)
		return "<";
	if(ac > bc)
		return ">";
	return "=";
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << solve(a, b, c);
	return 0;
}
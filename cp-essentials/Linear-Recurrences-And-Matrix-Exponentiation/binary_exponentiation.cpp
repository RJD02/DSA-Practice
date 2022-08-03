#include <bits/stdc++.h>
using namespace std;


int powr(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1)
			res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

int main(int argc, char const *argv[]) {
	cout << powr(2, 30);
	return 0;
}
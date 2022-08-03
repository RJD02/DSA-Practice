#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
	int ans = 0;
	while(x) {
		int last_bit_x = x & 1;
		int last_bit_y = y & 1;
		ans += last_bit_x xor last_bit_y;
		x >>= 1;
		y >>= 1;
	}
	return ans;
}
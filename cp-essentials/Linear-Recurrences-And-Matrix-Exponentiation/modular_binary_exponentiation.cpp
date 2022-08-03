#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int powr(long long int a, long long int b) {
	long long int res = 1;
	while(b) {
		if(b & 1) res *= a, res %= mod;
		a *= a; a %= mod;
		b >>= 1;
	}
}


int main(int argc, char const *argv[])
{
	
	return 0;
}
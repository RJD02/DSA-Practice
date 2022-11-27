#include <bits/stdc++.h>
using namespace std;

#define ld long double

int n;

ld dp(int zeros, int ones, int twos, int threes) {
	if (ones + twos + threes == 0)
		return 0;
	ld ans = n;
	if (ones) ans += ones * dp(zeros + 1, ones - 1, twos, threes);
	if (twos) ans += twos * dp(zeros, ones + 1, twos - 1, threes);
	if (threes) ans += threes * dp(zeros, ones, twos + 1, threes - 1);
	ans /= (ld)(n - zeros);
	return ans;
}

int main() {
	cin >> n;
	int v[n];
	int cnt[4];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		cnt[v[i]]++;
	}
	ld ans = dp(cnt[0], cnt[1], cnt[2], cnt[3]);
	cout << ans << endl;
	return 0;
}

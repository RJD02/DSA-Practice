#include <bits/stdc++.h>
using namespace std;

#define ld long double
const int N = 3000;
ld p[N], memo[N][N];
int n;

ld dp(int i, int h) {
	if (i == n)
		return 1.00;
	int t = n - i - h;
	ld &ans = memo[i][h];
	if (ans != -1.00) return ans;
	ans = 0.00;
	if (h)
		ans += dp(i + 1, h - 1) * p[i];
	if (t)
		ans += dp(i + 1, h) * (1 - p[i]);
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			memo[i][j] = -1.00;

	ld ans = 0;
	for (int i = (n / 2 + 1); i <= n; i++) {
		ans += dp(0, i);
	}
	cout << setprecision(10) << fixed;
	cout << ans << endl;
	return 0;
}
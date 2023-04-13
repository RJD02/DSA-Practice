#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3;
int dp[N][N];
int editDistance(string &s, string &t, int i = 0, int j = 0)
{
	if (i == s.size() and j == t.size()) return 0;
	if (i == s.size()) return t.size() - j;
	if (j == t.size()) return s.size() - i;
	if (dp[i][j] != 0) return dp[i][j];
	int ans = 0;
	if (s[i] != t[j]) {
		ans = 1 + min(editDistance(s, t, i + 1, j), min(editDistance(s, t, i, j + 1), editDistance(s, t, i + 1, j + 1)));
	}
	else {
		ans = editDistance(s, t, i + 1, j + 1);
	}
	dp[i][j] = ans;
	return ans;
}

int editDistanceDP(string s, string t) {
	int m = s.size(), n = t.size();
	int dp[m + 1][n + 1];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (s[i] != t[j])
				dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
			else
				dp[i][j] = dp[i - 1][j - 1];
		}
	}
	return dp[m][n];
}


int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistanceDP(s1, s2) << endl;
}
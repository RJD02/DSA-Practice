#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

int main() {
  int h, w;
  cin >> h >> w;
  string s[h];
  for(int i = 0; i < h; i++)
    cin >> s[i];

  int dp[h][w];
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(i == 0 and j == 0)
        dp[i][j] = 1;
      else if(i == 0)
        dp[i][j] = dp[i][j - 1];
      else if(j == 0)
        dp[i][j] = dp[i - 1][j];
      else {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      }
      if(s[i][j] == '#')
        dp[i][j] = 0;
      dp[i][j] %= mod;
    }
  }
  cout << dp[h - 1][w - 1] << endl;
  return 0;
}

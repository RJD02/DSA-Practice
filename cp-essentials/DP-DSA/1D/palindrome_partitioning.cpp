#include <bits/stdc++.h>
using namespace std;

string s;

bool isPalindrome(int i, int j) {
	while(i <= j) {
		if(s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

vector<vector<string>> dp(int i) {
	if(i == s.size()) return vector<vector<string>>();
	vector<vector<string>> ans;
	for(int j = i; j < s.size(); j++) {
		if(isPalindrome(i, j)) {
			vector<vector<string>> res = dp(j + 1);
			string sub = s.substr(i, j - i + 1);
			for(auto &x: res) {
				x.insert(x.begin(), sub);
			}
			if(res.size() == 0) {
				res.push_back({sub});
			}
			for(auto x: res)
				ans.push_back(x);
		}
	}
	return ans;
}

// Hello World

void solve() {
	string st;
	cin >> st;
	s = st;
	vector<vector<string>> res = dp(0);
	for(auto i: res) {
		for(auto j: i) 
			cout << j << " ";
		cout << endl;
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
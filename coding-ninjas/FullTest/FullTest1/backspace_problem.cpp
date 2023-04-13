#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '#') st.pop();
		else st.push(s[i]);
	}
	string res = "";
	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}
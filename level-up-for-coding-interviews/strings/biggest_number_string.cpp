#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
	string stra = to_string(a);
	string strb = to_string(b);
	if(stra.length() == strb.length())
		return (int)stra[0] > (int)strb[0];
	return stra.length() < strb.length();
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), compare);
	string res = "";
	for(auto ele: v)
		res += to_string(ele);
	cout << res;
}

int main() {
	solve();
	return 0;
}
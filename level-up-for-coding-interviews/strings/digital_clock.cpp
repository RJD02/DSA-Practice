#include <bits/stdc++.h>
using namespace std;

void solve() {
	int minutes;
	cin >> minutes;
	string output;
	output = to_string(minutes / 60) + ':';
	int remainder = minutes % 60;
	if(remainder < 10)
		output += '0';
	output += to_string(remainder);
	cout << output;
}

int main() {
	solve();
	return 0;
}
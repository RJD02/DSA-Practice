#include <bits/stdc++.h>
using namespace std;

// This is better than strtok
// This works on strings and char arrays

int main() {
	string input;
	getline(cin, input);
	stringstream ss(input);

	string token;
	vector<string> tokens;
	while(getline(ss, token, ' ')) {
		tokens.push_back(token);
	}
	for(auto token: tokens) {
		cout << token << ",";
	}
	return 0;
}
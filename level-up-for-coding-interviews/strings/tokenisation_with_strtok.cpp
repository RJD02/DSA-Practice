#include <bits/stdc++.h>
using namespace std;
// This only works on character array

int main() {

	char input[1000];
	cin.getline(input, 1000);

	// cout << strtok(input, " ") << endl;
	// cout << strtok(NULL, " ") << endl;
	// cout << strtok(NULL, " ") << endl;
	// cout << strtok(NULL, " ") << endl;
	// Above code works
	// This function internally maintains the string, you passed last time(in the last function call), by creating a static variable
	char *token = strtok(input, " ");
	vector<string> tokens;
	while (token != NULL) {
		tokens.push_back(token);
		token = strtok(NULL, " ");
	}

	for (auto token : tokens) {
		cout << token << endl;
	}

	return 0;

}
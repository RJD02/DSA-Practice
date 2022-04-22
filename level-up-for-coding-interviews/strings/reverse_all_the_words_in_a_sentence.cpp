#include <bits/stdc++.h>
using namespace std;

/*
Time complexity: O(n) n = number of characters including spaces
Space complexity: O(n) n = number of characters including spaces
The algorithm uses stringstream to create a buffer after which we tokenize the string with ' '(space) as delimiter
*/


int main() {
	string input; // O(N) N = number of characters including spaces -> space
	getline(cin, input);
	vector<string> tokens; // O(number of words) -> space
	stringstream ss(input); // O(N) N = number of characers including spaces -> space
	string token; // Temporary variable for storing itnermediate values
	// O(number of words) -> Time
	while(getline(ss, token, ' ')) {
		tokens.push_back(token);
	}
	// O(number of words) -> Time
	// Just printing in reverse order, the vector 
	for(int i = tokens.size() - 1; i > -1; i--) {
		cout << tokens[i] << " ";
	}
	return 0;
}
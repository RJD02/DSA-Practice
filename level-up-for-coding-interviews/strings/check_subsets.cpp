/*
Given two non-empty strings, write a function that determines whether the second string
is subsequence of first one

Sample input:
codingminutes
cines

Sample output:
Yes
*/
#include <bits/stdc++.h>
using namespace std;

// My logic is to store the first string in a set
// and for each character in subset_checking_string, we need to check
// if that char is present in the set
// Time complexity: O(n), where n = length of first string
// Space complexity: O(n), for set, where n = length of first string
void solveBySet() {
	unordered_set<char> st;
	string s;
	cin >> s;
	for(int i = 0; i < (int)s.size(); i++) {
		st.insert(s[i]);
	}
	string subset;
	cin >> subset;
	for(auto x: subset) {
		if(st.find(x) == st.end()) {
			cout << "False";
			return;
		}
	}
	cout << "True";
}

// Using two pointer
// One for first string
// Second for substring checking
// Time Complexity: O(n), where n = length of first string
// Space Complexity: O(1), because we use constant memory
void solveByTwoPointer() {
	string s, subset;
	cin >> s >> subset;
	int index_s = (int)s.size() - 1;
	int index_subset = (int)subset.size() - 1;
	while(index_subset > -1 and index_s > -1) {
		if(s[index_s] == subset[index_subset]) {
			index_subset--;
			index_s--;
		} else {
			index_s--;
		}
	}
	if(index_subset != -1)
		cout << "False";
	else
		cout << "True";
}

int main() {
	solveBySet();
	return 0;
}
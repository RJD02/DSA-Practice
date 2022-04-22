/*
Sorted Subsequences
Given a string, you need to print all subsequences of the string sorted by length
and lexicographic sorted order if length is same

Sample Input:
-------------
abcd

Sample Output:
--------------
, a, b, c, d, ab, ac, ad, bc, bd, cd, abc, abd, acd, bcd, abcd
*/
#include <bits/stdc++.h>
using namespace std;

bool cmpFunc(string a, string b) {
	if(a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

// Generating 2^n permutations..
void subsequence(string s, string o, vector<string> &v) {
	// Base case
	if(s.size() == 0) {
		v.push_back(o);
		return;
	}
	// Recursion case
	char ch = s[0];
	string reduced_input = s.substr(1);
	subsequence(reduced_input, o + ch, v);
	subsequence(reduced_input, o, v);
}

void solve() {
	string s;
	cin >> s;
	vector<string> v;
	string output = "";
	subsequence(s, output, v);
	
	sort(v.begin(), v.end(), cmpFunc); // O(nlogn)
	for(auto ele: v) // O(n)
		cout << ele << " ";
}

#include <bits/stdc++.h>
using namespace std;

int main() {
	solve();
	return 0;
}
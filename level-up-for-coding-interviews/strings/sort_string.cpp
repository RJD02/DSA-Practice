#include <bits/stdc++.h>
using namespace std;
// Given a list of 'n' strings S0,S1,S2...Sn-1, each consisting of digits and spaces, the number of spaces is teh same for each entry, the goal is to implement a variation of a sort command.
// None of the strings contains consecutive spaces. Also, no string starts with a space nor ends with it.
// Spaces are used to divide string into columns, which can be used as keys in comparisons.

/*
This is hell lot of question statement.
The program has to support the required parameters:
key: integer denoting the column used as a key in comparisons. the left-most column is denoted by 1.

Reversed: boolean vairable indicating whether to reverse the result of comparisons.

Comparison-type:either lexicographic or numeric. Lexicographic means that we use Lexicographical order where for example (122 < 13)

Numeric: means that we compare the strings by their numerical values, so (13 < 122).
If the comparison type is 'numeric' and numeric value of keys Si and Sj are equal for i < j, then Si is considered strictly smaller than Sj because it comes first.
*/

/*
Sample input
------------
3
92 022
82 12
77 13
2 false numeric

Sample Output
-------------
3
82 12
77 13
92 022

Explanation
-----------
The key for ordering is 2, reversal is false and order is numeric
Therefore, the keys 022, 12 and 13 should be ordered as 12, 13 and 022
Therefore, the final output is 82, 12, 77 13 and 92 022.
*/

/*
Logic->
-------
1. Extract keys from every string(row)
-> Use tokenization while separating the numbers with spaces
-> pair<string, int>
2. Do sorting
-> Two comparators : i) lexicographic, ii) Numeric
3. If reverse parameter is true, reverse the vector generated from above steps
*/

string tokenizer(string input, int key) {
	stringstream ss(input);
	string token;
	while(getline(ss, token, ' ') and key > 1) {
		key--;
	}
	return token;
}

int convertToInt(string s) {
	int ans = 0;
	int p = 1;
	for(int i = s.size() - 1; i > -1; i--) {
		ans += (s[i] - '0') * p;
		p *= 10;
	}
	return ans;
}

bool lexicographicCompare(pair<string, string> s1, pair<string, string> s2) {
	string key1 = s1.second;
	string key2 = s2.second;

	return key1 < key2;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
	string key1 = s1.second;
	string key2 = s2.second;
	return convertToInt(key1) < convertToInt(key2);
}

int main() {
	string is_reverse;
	string cmp_type;
	int key;
	int n;
	cin >> n;
	cin.get();
	vector<string> strings(n);
	for (int i = 0; i < n; i++) {
		getline(cin, strings[i]);
	}
	cin >> key >> is_reverse >> cmp_type;
	vector<pair<string, string>> data;
	for(int i = 0; i < n; i++) {
		string token = tokenizer(strings[i], key);
		data.push_back({strings[i], token});
	}

	// 2. sorting
	// if numeric
	if(cmp_type == "numeric") {
		sort(data.begin(), data.end(), numericCompare);
	} else {
		sort(data.begin(), data.end(), lexicographicCompare);
	}

	if (is_reverse == "true") {
		reverse(data.begin(), data.end());
	}
	for(auto d: data) {
		cout << d.first << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

string addNumbers(string n1, string n2) {
	if(n1.size() > n2.size())
		swap(n1, n2);
	string result = "";

	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	// Add digits upto n1.length()
	int carry = 0;
	for(int i = 0; i < n1.length(); i++) {
		int d1 = n1[i] - '0';
		int d2 = 0;
		if(i < n2.length())
			d2 = n2[i] - '0';
		int sum = d1 + d2 + carry;
		carry = sum / 10;
		result.push_back(sum % 10 + '0');
	}

	for(int i = n1.length(); i < n2.length(); i++) {
		int d2 = n2[i] - '0';
		int sum = d2 + carry;
		carry = sum / 10;
		result.push_back(sum % 10 + '0');
	}
	// If carry is generated
	if(carry)
		result.push_back('1');
	reverse(result.begin(), result.end());
	return result;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	cout << addNumbers(s1, s2);
	return 0;
}
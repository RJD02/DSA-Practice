#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	string s1 = "", s2 = "";
	for(int i = 0; i < s.size(); i++)
		if(i % 2 == 0)
			s1 += s[i];
		else
			s2 += s[i];
	cout << s1 << endl << s2 << endl;
}
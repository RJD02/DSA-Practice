#include <bits/stdc++.h>
using namespace std;

void twoerOfHanaoi(int n, char s, char h, char d) {
	if(n == 1) {
		cout << "Move 1st disk from " << s << " to" << d << endl;
		return;
	}
	twoerOfHanaoi(n - 1, s, d, h);
	cout << "Move " << n << "Th disk from " << s << " to" << d;
	twoerOfHanaoi(n - 1, h, s, d);
}
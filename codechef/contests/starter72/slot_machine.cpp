#include <bits/stdc++.h>
using namespace std;

void solve() {
	string name;
	int year;
	char alpha;
	cin >> name >> year >> alpha;
	unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	int x = 0;
	for(auto i: name) {
		if(vowels.find(i) != vowels.end()) {
			x++;
		}
	}
	int y = 0;
	while(year) {
		y += year % 10;
		year /= 10;
	}

	int z = tolower(alpha) - 'a' + 1;
	int X = 0;
	while(x) {
		X += x % 10;
		x /= 10;
	}
	int Y = 0;
	while(y) {
		Y += y % 10;
		y /= 10;
	}
	int Z = 0;
	while(z) {
		Z += z % 10;
		z /= 10;
	}
	cout << X << " " << Y << " " << Z << endl;
	if(X == Y and Y == Z)
		cout << 1;
	else
		cout << 0;
}

int main() {
	solve();
}
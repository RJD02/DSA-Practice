#include <bits/stdc++.h>
using namespace std;


// First part
void first() {
	char a, b;
	string line;
	int points = 0;
	unordered_map<char, int> score;
	score['X'] = 1;
	score['Y'] = 2;
	score['Z'] = 3;
	while(cin >> a >> b) {
		// all win conditions
		if((a == 'A' and b == 'Y') or (a == 'B' and b == 'Z') or (a == 'C' and b == 'X'))
			points += 6 + score[b];

		// draw conditions
		else if((a == 'A' and b == 'X') or (a == 'B' and b == 'Y') or (a == 'C' and b == 'Z'))
			points += 3 + score[b];

		else
			points += score[b];

	}
	cout << points;
}


void second() {
	char a, b;
	string line;
	int points = 0;
	unordered_map<char, int> score;
	unordered_map<char, char> win, lose;
	score['A'] = 1;
	score['B'] = 2;
	score['C'] = 3;

	lose['A'] = 'C';
	lose['B'] = 'A';
	lose['C'] = 'B';

	win['A'] = 'B';
	win['B'] = 'C';
	win['C'] = 'A';

	while(cin >> a >> b) {
		if(b == 'X')
			points += score[lose[a]];
		if(b == 'Y')
			points += score[a] + 3;
		if(b == 'Z')
			points += score[win[a]] + 6;
	}
	cout << points << endl;
}

int main() {
	// first();
	second();
	return 0;
}
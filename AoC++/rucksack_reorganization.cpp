#include <bits/stdc++.h>
using namespace std;

void first() {

	string line;
	int prioritySum = 0;
	while (cin >> line) {
		string first(line.begin(), line.begin() + line.size() / 2);
		string second(line.begin() + line.size() / 2, line.end());
		cout << first << " " << second << endl;

		for (auto i : first) {
			if (second.find(i) != string::npos) {
				int index = second.find(i);
				if (second[index] >= 'a' and second[index] <= 'z') {
					// lower letter
					prioritySum += (int)(second[index] - 'a') + 1;
				} else if (second[index] >= 'A' and second[index] <= 'Z') {
					prioritySum += (int)(second[index] - 'A') + 27;
				}
				break;
			}

		}
	}
	cout << prioritySum << endl;
}

void second() {
	string line1, line2, line3;
	int prioritySum = 0;
	while (cin >> line1 >> line2 >> line3) {
		for (auto i : line1) {
			if (line2.find(i) != string::npos and line3.find(i) != string::npos) {
				int index = line2.find(i);
				if (line2[index] >= 'a' and line2[index] <= 'z') {
					// lower letter
					prioritySum += (int)(line2[index] - 'a') + 1;
				} else if (line2[index] >= 'A' and line2[index] <= 'Z') {
					prioritySum += (int)(line2[index] - 'A') + 27;
				}
				break;
			}
		}
	}
	cout << prioritySum << endl;
}

int main() {
	// first();
	second();
	return 0;
}
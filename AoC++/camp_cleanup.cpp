#include <bits/stdc++.h>
using namespace std;

template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

// Call it as vector<string> arr = split(s, ' ');


void first() {
	string line;
	int count = 0;
	while (cin >> line) {
		vector<string> temp = split(line, ',');
		vector<pair<int, int>> v;
		for (auto i : temp) {
			vector<string> s = split(i, '-');
			v.push_back({stoi(s[0]), stoi(s[1])});
		}
		sort(v.begin(), v.end());
		if (v[0].second >= v[1].second and v[0].first <= v[1].first) {
			// cout << v[0].first << " " << v[0].second << endl;
			// cout << v[1].first << " " << v[1].second << " Yes" << endl << endl;
			count++;
		}
	}
	cout << count << endl;
}

int main() {
	first();
	return 0;
}
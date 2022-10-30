#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b) {
	return a[a.size() - 1] < b[b.size() - 1];
}

int main() {
	vector<string> names = {"ram", "raj", "ravi"};

	sort(names.begin(), names.end(), comp);

	for(auto name: names)
		cout << name << " ";

	return 0;
}
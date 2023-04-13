#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int main() {
	unordered_map<int, int> mp;
	vector<int> v;
	string s;
	int sum = 0;
	while(getline(cin , s)) {
		if(s == "") {
			v.push_back(sum);
			sum = 0;
		} else {
			sum += stoi(s);
		}
	}
	cout << *max_element(v.begin(), v.end());
	return 0;
}

int helloWorld() {
	int a;
	cin >> a;
	cout << a;
	return 0;
}

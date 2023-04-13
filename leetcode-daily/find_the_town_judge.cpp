#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int findJudge(int n, vector<vector<int>> trust) {

	if(trust.size() == 0)
		return n == 1 ? 1 : -1;
	vector<int> incoming(n + 1);
	vector<int> outgoing(n + 1);
	for(auto i: trust) {
		outgoing[i[0]]++;
		incoming[i[1]]++;
	}
	for(int i = 0; i <= n; i++) {
		
		if(incoming[i] == n - 1 and outgoing[i] == 0)
			return i;
	}
	return -1;
}

int findJudgeSecond(int n, vector<vector<int>> trust) {
	if(trust.size() == 0)
		return n == 1 ? 1: -1;
	vector<int> v(n + 1, 0);
	for(auto i: trust) {
		v[i[0]]--;
		v[i[1]]++;
	}
	for(auto i: v) {
		if(i >= 0)
			return i;
	}
	return -1;
}

int main() {
	vector<vector<int>> trust = {};
	cout << findJudge(3, trust) << endl;
	return 0;
}

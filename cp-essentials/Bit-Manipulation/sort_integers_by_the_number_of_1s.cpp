#include <bits/stdc++.h>
using namespace std;

int countBits(int n) {
	int ans = 0;
	while(n) {
		n = n & (n - 1);
		ans++;
	}
	return ans;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

vector<int> sortByBits(vector<int> arr) {
	int n = arr.size();
	vector<pair<int, int>> vp;
	for(auto i: arr) {
		vp.push_back({countBits(i), i});
	}
	sort(vp.begin(), vp.end(), cmp);
	vector<int> res;
	for(auto i: vp) {
		res.push_back(i.second);
	}
	return res;
}
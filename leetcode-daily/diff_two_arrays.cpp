// 23-01-22
#include <atomic>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

vector<vector<int>> findDifference(vector<int> nums1, vector<int> nums2) {
	unordered_set<int> s1(nums1.begin(), nums1.end());
	unordered_set<int> s2(nums2.begin(), nums2.end());
	vector<vector<int>> ans;
	ans.push_back(vector<int>());
	ans.push_back(vector<int>());

	for(auto i: s1)
	if(s2.find(i) == s2.end())
		ans[0].push_back(i);
	for(auto i: s2)
	if(s1.find(i) == s1.end())
		ans[1].push_back(i);
	return ans;
}
int main() {
	vector<int> nums1 = {1, 2, 3};
	vector<int> nums2 = {2, 4, 6};
	for(auto i: findDifference(nums1, nums2)) {
		for(auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
}

int findCenter(vector<vector<int>> edges) {
	map<int, int> map;
	for(int i = 0; i < (int)edges.size(); i++) {
		map[edges[i][0]]++;
		map[edges[i][1]]++;
	}
	// for(auto r: map) {
	// 	cout << r.first << " " << r.second << endl;
	// }
	auto res = max_element(map.begin(), map.end(), compare);
	return res->first;
}

int main() {
	vector<vector<int>> edges;
	edges.push_back({1, 2});
	edges.push_back({2, 3});
	edges.push_back({4, 2});
	cout << findCenter(edges);
	return 0;
}
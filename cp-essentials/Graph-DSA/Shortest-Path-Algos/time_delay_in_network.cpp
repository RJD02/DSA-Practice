#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

int networkDelayTime(vector<vector<int>> times, int n, int k) {
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	unordered_map<int, vector<pi>> adjList;
	for(auto i: times) {
		int u = i[0], v = i[1], wt = i[2];
		adjList[u].push_back({v, wt});
	}
	vector<int> dist(n, INT_MAX);
	pq.push({0, k});
	dist[k] = 0;
	while(!pq.empty()) {
		int u = pq.top().second; pq.pop();
		for(auto [target, wt]: adjList[u]) {
			if(dist[target] > dist[u] + wt) {
				dist[target] = dist[u] + wt;
				pq.push({dist[target], target});
			}
		}
	}
	int totalDist = 0;
	for(auto i: dist) {
		cout << i << " ";
		if(i == INT_MAX)
			continue;
		totalDist += i;
	}
	cout << endl;
	if(totalDist == 0)
		return -1;
	return totalDist;
}

int main() {
	vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
	int n = 4;
	int k = 2;
	cout << networkDelayTime(times, n, k) << endl;
	return 0;
}
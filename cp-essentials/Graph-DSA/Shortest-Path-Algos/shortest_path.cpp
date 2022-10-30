#include<bits/stdc++.h>
using namespace std;

#define pi pair<int, int>

vector<int> shortestPath(vector<vector<int>> roads,int n){
	unordered_map<int, vector<pi>> adjList;
	for(auto i: roads) {
		int u = i[0], v = i[1], wt = i[2];
		adjList[u].push_back({v, wt});
		adjList[v].push_back({u, wt});
	}
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({0, 1});
	vector<int> dist(n + 1, INT_MAX);
	vector<vector<int>> path(n + 1);
	for(int i = 1; i < n + 1; i++) {
		path[i].push_back(1);
	}
	dist[1] = 0;
	while(!pq.empty()) {
		int src = pq.top().second;
		pq.pop();

		for(auto [target, wt]: adjList[src]) {
			if(dist[target] > dist[src] + wt) {
				path[target].push_back(src);
				dist[target] = dist[src] + wt;
				pq.push({dist[target], target});
			}
		}
	}
	for(auto i: dist)
		cout << i << " ";
	cout << endl;
	path[n].push_back(n);
	return path[n];
}

int main() {
	vector<vector<int>> edges = {{1,2,2},{2, 5, 5},{2, 3, 4},{1, 4, 1},{4, 3, 3},{3, 5, 1}};
	int n = 5;
	auto res = shortestPath(edges, n);
	for(auto i: res)
		cout << i << " ";
}
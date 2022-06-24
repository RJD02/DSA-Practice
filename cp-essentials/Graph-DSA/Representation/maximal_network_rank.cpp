#include <bits/stdc++.h>
using namespace std;

int maxNetworkRank(int n, vector<vector<int>> roads) {
	// for (auto edge : roads) {
	// 	// cout << "Hello" << endl;
	// 	for(auto ele: edge) {
	// 		cout << ele << " ";
	// 	}
	// 	cout << endl;
	// }
	int deg[n];
	bool edges[n][n];
	memset(deg, 0, sizeof(deg));
	memset(edges, 0, sizeof(edges));
	for (int i = 0; i < roads.size(); i++) {
		int city1 = roads[i][0], city2 = roads[i][1];
		// cout << city1 << " " << city2 << endl;
		deg[city1]++;
		deg[city2]++;
		edges[city1][city2] = true;
		edges[city2][city1] = true;
	}
	// for(auto d: deg) {
	// 	cout << d << " ";
	// }
	cout << endl;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ans = max(ans, deg[i] + deg[j] - edges[i][j]);
		}
	}
	return ans;
}

int main() {

	int n, totalEdges;
	cin >> n >> totalEdges;
	vector<vector<int>> roads(totalEdges);
	for (int i = 0; i < totalEdges; i++) {
		int src, dest;
		cin >> src >> dest;
		// cout << src << " " << dest << endl;
		roads[i] = {src, dest};
	}
	// for(auto edges: roads) {
	// 	for(auto ele: edges) {
	// 		cout << ele << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << maxNetworkRank(n, roads);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<pair<int, int>>> adjList;

void addEdge(int x, int y, int w) {
	adjList[x].push_back({y, w});
	adjList[y].push_back({x, w});
}

int primMST() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	bool *visited = new bool[adjList.size()]{false};
	int ans = 0;
	q.push({0, 0});

	while(!q.empty()) {
		auto [wt, node] = q.top();
		q.pop();
		if(visited[node])
			continue;
		ans += wt;
		visited[node] = 1;

		for(auto x: adjList[node]) {
			if(visited[x.first] == 0) {
				q.push({x.second, x.first});
			}
		}

	}
	return ans;
}

int main() {
	int n, m;
	cin >> n >> m;
	adjList.clear();

	for(int i = 0; i < n; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		addEdge(x - 1, y - 1, w);
	}
	cout << primMST() << endl;
}
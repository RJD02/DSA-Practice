#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> adjList, unordered_map<int, bool> &st, vector<bool> &visited, int node) {
	if(visited[node] and st[node])
		return true;
	visited[node] = true;
	st[node] = true;
	bool ok = false;
	for(auto i: adjList[node]) {
		ok = max(ok, dfs(adjList, st, visited, i));
	}
	st[node] = false;
	return ok;
}

bool solve(int n, vector<vector<int>> edges) {
	vector<vector<int>> adjList(n + 1);
	for(auto i: edges) {
		adjList[i[0]].push_back(i[1]);
	}
	vector<bool> visited(n + 1);
	unordered_map<int, bool> st;
	return dfs(adjList, st, visited, 0);
}

void isCyclic() {
	int n, e;
	cin >> n >> e;
	vector<vector<int>> edges;
	for(int i = 0; i < e; i++) {
		int ui, vi;
		cin >> ui >> vi;
		edges.push_back({ui, vi});
	}
	cout << solve(n, edges) << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
		isCyclic();
	return 0;
}
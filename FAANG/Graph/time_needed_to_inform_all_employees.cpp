#include <bits/stdc++.h>
using namespace std;

// BFS
int numOfMinutesBFS(int n, int headID, vector<int>& manager, vector<int>& informTime) {
	vector<int> dist(n, 0);
	vector<vector<int>> adjList(n);
	for (int i = 0; i < n; i++) {
		if (i == headID)
			continue;
		adjList[manager[i]].push_back(i);
	}
	vector<bool> visited(n, false);
	queue<int> q;
	q.push(headID);
	int mins = 0;
	while (!q.empty()) {
		int node = q.front(); q.pop();
		for (auto i : adjList[node]) {
			if (!visited[i]) {
				visited[i] = true;
				dist[i] = dist[node] + informTime[node];
				mins = max(mins, dist[i]);
				q.push(i);
			}
		}
	}
	return mins;
}


// dfs

void dfs(int headID, vector<bool>& visited, vector<vector<int>> &adjList, vector<int> &dist, vector<int> &informTime) {
	visited[headID] = true;
	for(auto i: adjList[headID]) {
		if(!visited[i]) {
			dist[i] = dist[headID] + informTime[headID];
			dfs(i, visited, adjList, dist, informTime);
		}
	}
}

int numOfMinutesDFS(int n, int headID, vector<int>& manager, vector<int>& informTime) {
	vector<vector<int>> adjList(n);
	vector<bool> visited(n, 0);
	vector<int> dist(n, 0);
	for(int i = 0; i < n; i++) {
		if(i == headID)
			continue;
		adjList[manager[i]].push_back(i);
	}
	dfs(headID, visited, adjList, dist, informTime);
	return *max_element(dist.begin(), dist.end());
}
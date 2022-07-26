#include <bits/stdc++.h>
using namespace std;

// Using Bellman-Ford algorithm
// O(N * E) time
// O(N) space
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	vector<int> dist(n, INT_MAX - 101);
	dist[k - 1] = 0;
	for (int i = 0; i < n - 1; i++) {
		bool changed = false;
		for (auto j : times) {
			int u = j[0] - 1, v = j[1] - 1, wt = j[2];
			if (dist[v] > dist[u] + wt) {
				dist[v] = dist[u] + wt;
				changed = true;
			}
		}
		if (!changed)
			break;
	}
	int ans = *max_element(dist.begin(), dist.end());
	return ans == INT_MAX - 101 ? -1 : ans;
}

// Dijkstra's algorithm
// Using priority queue...
int networkTimeDelayPQ(vector<vector<int>> &times, int n, int k) {
	vector<int> dist(n + 1, INT_MAX - 101);
	vector<map<int, int>> adjList(n + 1);
	dist[k] = 0;
	for (auto i : times) {
		adjList[i[0]][i[1]] = i[2];
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, k});
	while (!pq.empty()) {
		int node = pq.top().second; pq.pop();

		for (auto i : adjList[node]) {
			int v = i.first, w = i.second;
			if (dist[v] > dist[node] + w) {
				dist[v] = dist[node] + w;
				pq.push({dist[v], v});
			}
		}
	}
	int ans = *max_element(dist.begin() + 1, dist.end());
	return ans == INT_MAX - 101 ? -1 : ans;
}

// Using queue
int networkTimeDelay(vector<vector<int>>& times, int n, int k) {
	vector<int> dist(n + 1, INT_MAX - 101);
	vector<map<int, int>> adjList(n + 1);
	for (auto i : times) {
		adjList[i[0]][i[1]] = i[2];
	}
	queue<int> q;
	q.push(k);
	dist[k] = 0;
	while (!q.empty()) {
		int node = q.front(); q.pop();

		for (auto i : adjList[node]) {
			int v = i.first, w = i.second;
			if (dist[v] > dist[node] + w) {
				dist[v] = dist[node] + w;
				q.push(v);
			}
		}
	}
	int maxDelayTime = 0;
	for (int i = 1; i < n + 1; i++) {
		if (dist[i] == INT_MAX - 101)
			return -1;
		maxDelayTime = max(maxDelayTime, dist[i]);
	}
	return maxDelayTime;
}
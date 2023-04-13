#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int node, vector<int> edges) {
	vector<int> dist(edges.size(), -1);
	vector<bool> visited(edges.size(), false);
	queue<int> q;
	q.push(node);
	visited[node] = true;
	int count = 1;
	int level = 0;
	while(!q.empty()) {
		int n = q.front();
		q.pop();
		dist[n] = level;
		if(edges[n] != -1 and !visited[edges[n]]) {
			q.push(edges[n]);
			visited[edges[n]] = true;
		}
		count--;
		if(count == 0) {
			count = q.size();
			level++;
		}

	}
	return dist;
}

int closestMeetingNode(vector<int> edges, int node1, int node2) {
	// bfs on node 1 and node2
	// get common indices with their distances
	// calculate max between them
	vector<int> distN1 = bfs(node1, edges);
	vector<int> distN2 = bfs(node2, edges);
	for(auto i: distN1)
		cout << i << " ";
	cout << endl;
	for(auto i: distN2)
		cout << i << " ";
	cout << endl;
	int commonIndex = -1, minDist = INT_MAX;
	for(int i = 0; i < edges.size(); i++) {
		if(distN2[i] != -1 and distN1[i] != -1) {
			int dist1 = distN1[i], dist2 = distN2[i];
			if(minDist > max(dist1, dist2) ) {
				commonIndex = i;
				minDist = max(dist1, dist2);
			}
		}
	}
	return commonIndex;
}

int main() {
	vector<int> edges = {4, 4, 4, 5, 1, 2, 2};
	int node1 = 1;
	int node2 = 1;
	cout << closestMeetingNode(edges, node1, node2);
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

int messageRoute(int n, vector<vector<int>> edges) {
	queue<int> q;
	q.push(1);

	// Adjacency list
	vector<vector<int>> adjList(n + 1);
	for(int i = 1; i < (int)edges.size(); i++) {
		auto a = edges[i];
		adjList[a[0]].push_back(a[1]);
		adjList[a[1]].push_back(a[0]);
	}

	vector<int> dist(n + 1, 0);
	vector<int> visited(n + 1, 0);
	visited[1] = 1;

	while(!q.empty()) {
		int source = q.front();
		q.pop();
		for(auto nbr: adjList[source]) {
			if(!visited[nbr]) {
				visited[nbr] = 1;
				q.push(nbr);
				dist[nbr] = dist[source] + 1;
			}
		}
	}


	return dist[n] + 1;
}
int main() {
	int noVertices, noEdges;
	cin >> noVertices >> noEdges;
	vector<vector<int>> edges(noEdges + 1);
	for (int i = 1; i <= noEdges; i++) {
		int ui, vi;
		cin >> ui >> vi;
		edges[i] = {ui, vi};
	}
	cout << messageRoute(noVertices, edges) << endl;
	return 0;
}
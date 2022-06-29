#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>> graph) {

	auto bfs = [&] (int source = 0) {
		vector<bool> visited(graph.size());
		vector<int> parent(graph.size());
		parent[source] = -1;
		queue<int> q;
		q.push(source);
		visited[source] = true;

		while(!q.empty()) {
			int node = q.front(); q.pop();

			for(auto nbr: graph[node]) {
				if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = node; 
				} else if(parent[node] != nbr) {
					return true;
				}
			}
		}
		return false;
	};

	bfs(0);

	return false;
}
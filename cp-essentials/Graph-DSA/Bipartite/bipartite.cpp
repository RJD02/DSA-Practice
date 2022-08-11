#include <bits/stdc++.h>
using namespace std;

/*

Given an undirected graph with n nodes, where each nodes is numbered 0 to  n-1.

You are given a 2D array, where for each v in graph[u] there is an undirected edge between node u and v.
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

Return whether Graph is Bipartite or not.

Constraints:

    1 <= n <= 100

*/

bool dfs_helper(vector<vector<int>> graph, int node, int parent, int *visited, int color) {
	visited[node] = 1; // 1 or 2.. Both mean visited
	for(auto i: graph[node]) {
		// if nbr is not visited
		if(color[i] == 0) {
			bool prob = dfs_helper(graph, i, node visited, 3 - color);
			if(prob == false)
				return false;
		}
		else if(i != parent and color = visited[i])
			return false;

	}
	return true;
}

// is given graph bipartite
bool dfs(vector<vector<int>> graph, int n) {
	int visited[n] = {0} // 0 -> not visited, 1 -> color1, 2 -> color2

	// Assuming there's only one connected component
	int color = 1;
	dfs_helper(graph, 0, visited, color);
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	while(m--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);

	}

	// BFS or DFS by coloring the nodes
	// if current node has color 1 then it's all neighbouring nodes should have color 2

	return 0;
}
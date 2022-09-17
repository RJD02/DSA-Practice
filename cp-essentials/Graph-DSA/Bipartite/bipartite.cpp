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

bool dfs_helper(vector<int> graph[],int node,int *visited,int parent, int color){
	//come to node
	visited[node] = color; //1 or 2, both mean visited

	for(auto nbr : graph[node]){

		if(visited[nbr]==0){
			int subprob = dfs_helper(graph,nbr,visited,node,3-color);
			
			if(subprob==false){
				return false;
			}

		}
		else if(nbr!=parent and color==visited[nbr]){
			return false;
		}

	}
	return true;
}

bool bipartite_helper(vector<vector<int>> graph, int node, int *visited, int parent, int color) {
	visited[node] = color;
	for(auto nbr: graph[node]) {
		if(visited[nbr] == 0) {
			int subprob = bipartite_helper(graph, nbr, visited, node, 3 - color);
			if(!subprob)
				return false;
		} else if(nbr != parent and color == visited[nbr])
		return false;
	}
	return true;
}

bool isBipartite(vector<vector<int>> graph) {
	int n = graph.size();
	int visited[n] = {0};
	int color = 1;
	int ans = bipartite_helper(graph, 0, visited, -1, color);
	return ans;
}


bool dfs(vector<int> graph[],int N){

	int visited[N] = {0};  // 0- Not Visited, 1 - Visited Color is 1, 2 - Visted Color 2

	int color = 1;
	int ans = dfs_helper(graph,0,visited,-1,color);
	//later one

	//colors
	for(int i=0;i<N;i++){
		cout<<i<<" - Color "<<visited[i] <<endl;
	}

	//
	return ans;
}
int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<int> graph[n];
	while(m--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);

	}

	// BFS or DFS by coloring the nodes
	// if current node has color 1 then it's all neighbouring nodes should have color 2
	if(dfs(graph, n))
		cout << "Bipartite";
	else
		cout << "not a bipartite";
	return 0;
}
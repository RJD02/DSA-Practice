#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int rank[100000];

int find_set(int v) {
	if(parent[v] == -1)
		return v;
	return find_set(parent[v]);
}

void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	if(a != b)
		parent[b] = a;
}

vector<bool> DSU(vector<vector<int>> query) {
	memset(parent, -1, sizeof parent);
	// memset(rank, 0, sizeof rank);
	vector<bool> res;
	for(auto i: query) {
		int x = i[0], u = i[1], v = i[2];
		// Unite u and v
		if(x == 1)
			union_sets(u, v);
		else {
			res.push_back(find_set(u) == find_set(v));
		}
	}
	return res;
}

int contains_cycle(unordered_map<int, vector<int>> l) {
	memset(parent, -1, sizeof parent);
	int count = 0;
	for(auto edge: l) {
		int i = edge.second[0];
		int j = edge.second[1];

		int s1 = find_set(i);
		int s2 = find_set(j);

		if(s1 != s2)
			++count;
	}
	return count;
}

// bool contains_cycle(unordered_map<int, vector<int>> l) {
// 	memset(parent, -1, sizeof parent);
// 	for(auto edge: l) {
// 		int i = edge[0];
// 		int j = edge[1];
// 		int s1 = find_set(i);
// 		int s2 = find_set(j);

// 		if(s1 != s2)
// 			union_sets(s1, s2);
// 		else
// 			return true;
// 	}
// 	return false;
// }

int makeConnected(int n, vector<vector<int>> connections) {
	unordered_map<int, vector<int>> adjList;
	for(auto i: connections) {
		int u = i[0], v = i[1];
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	return contains_cycle(adjList);
}

int main() {
	vector<vector<int>> query = {{1,1,2},{1,1,3},{2,1,4},{2,2,3}};
	cout << makeConnected(4, {{0,1},{0,2},{1,2}}) << endl;
	return 0;
}
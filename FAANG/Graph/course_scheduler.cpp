#include <bits/stdc++.h>
using namespace std;

// Requires topological sort
bool canFinish(int n, vector<vector<int>>& prerequisites) {
	vector<vector<int>> adjList(n);
	vector<int> inDegree(n);
	for(auto i: prerequisites) {
		adjList[i[1]].push_back(i[0]);
		inDegree[i[0]]++;
	}
	// Topological sort
	stack<int> st;

	for(int i = 0; i < n; i++) {
		if(inDegree[i] == 0)
			st.push(i);
	}

	int count = 0;

	while(!st.empty()) {
		int node = st.top(); st.pop();
		count++;
		for(auto i: adjList[node]) {
			inDegree[i]--;
			if(inDegree[i] == 0)
				st.push(i);
		}
	}
	// count < n => unconnected
	// count > n => cyclic
	return count == n;
}
#include<bits/stdc++.h>

using namespace std;

int messageRoute(int n, vector<vector<int>> edges) {
	list<int> l[n + 1];
	for (auto nbr : edges) {
		int first = nbr[0];
		int second = nbr[1];
		l[first].push_back(second);
		// l[second].push_back(first);
	}

	// for(auto e: l) {
	// 	cout << e.size() << " ";
	// 	for(auto nbr: e) {
	// 		cout << nbr << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "END" << endl;

	queue<int> q;
	q.push(1);

	bool visited[n + 1];
	bool dist[n + 1];


	memset(dist, 0, sizeof dist);
	memset(visited, 0, sizeof visited);

	dist[1] = 0;
	visited[1] = true;

	while (!q.empty()) {
		int f = q.front();

		q.pop();
		for(auto a: l[f]) {
			cout << a << " ";
		}
		cout << endl;
		for (auto nbr : l[f]) {
			if (!visited[nbr]) {
				q.push(nbr);
				visited[nbr] = true;
				dist[nbr] = dist[f] + 1;
			}
		}
	}
	// for (int i = 1; i < sizeof(dist); i++ ) {
	// 	cout << dist[i] << " ";
	// }
	// cout << endl;
	if (visited[n]) {
		return dist[n];
	} else {
		return -1;
	}
}

int main() {
	int noVertices, noEdges;
	cin >> noVertices >> noEdges;
	vector<vector<int>> edges(0, vector<int>(0));
	for (int i = 0; i < noEdges; i++) {
		int ui, vi;
		cin >> ui >> vi;
		edges.push_back({ui, vi});
	}
	cout << messageRoute(noVertices, edges);
	return 0;
}
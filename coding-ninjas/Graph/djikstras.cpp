#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // pair of (vertex, distance)

vector<int> dijkstra(vector<vector<pii>>& graph, int source) {
	int n = graph.size();
	vector<int> distance(n, INT_MAX);
	distance[source] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap queue
	pq.push({0, source});

	while (!pq.empty()) {
		int current_vertex = pq.top().second;
		int current_distance = pq.top().first;
		pq.pop();

		if (current_distance > distance[current_vertex])
			continue;

		for (auto neighbor : graph[current_vertex]) {
			int neighbor_vertex = neighbor.first;
			int neighbor_distance = neighbor.second;
			int distance_to_neighbor = current_distance + neighbor_distance;
			if (distance_to_neighbor < distance[neighbor_vertex]) {
				distance[neighbor_vertex] = distance_to_neighbor;
				pq.push({distance_to_neighbor, neighbor_vertex});
			}
		}
	}

	return distance;
}

int main() {
	int V, E;
	cin >> V >> E;
	vector<vector<pii>> graph(V);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	vector<int> distances = dijkstra(graph, 0);
	for (int i = 0; i < V; i++)
		cout << i << " " << distances[i] << endl;

	return 0;
}

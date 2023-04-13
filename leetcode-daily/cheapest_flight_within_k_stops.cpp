#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> flights, int src, int dst, int k) {
	// apply dijkstra's algo
	unordered_map<int, vector<pair<int, int>>> adjList;
	for(auto i: flights) {
		adjList[i[0]].push_back({i[1], i[2]});
	}
	for(auto i: adjList) {
		cout << i.first << ": ";
		for(auto j: i.second)
			cout << j.first << " ";
		cout << endl;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> prices(flights.size(), INT_MAX);
	pq.push({0, src});
	k++;
	prices[src] = 0;
	while(!pq.empty() and k) {
		int u = pq.top().second;
		pq.pop();
		for(auto i: adjList[u]) {
			int v = i.first;
			int price = i.second;
			// cout << v << " ";

			if(prices[v] > prices[u] + price) {
				prices[v] = prices[u] + price;
				pq.push({prices[v], v});
				if(v == dst)
					return prices[v];
			}
		}
		k--;
	}

	return prices[dst] == INT_MAX ? -1: prices[dst];
}

int findCheapestPrice2(int n, vector<vector<int>> flights, int src, int dst, int k) {
	unordered_map<int, vector<pair<int, int>>> adjList;
	for(auto i: flights) adjList[i[0]].push_back({i[1], i[2]});
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({0, src, k + 1});
	while(!pq.empty()) {
		auto d = pq.top(); pq.pop();
		int node = d[1], cost = d[0], stops = d[2];
		if(node == dst)
			return cost;
		if(stops > 0) {
			for(auto i: adjList[node]) {
				pq.push({cost + i.second, i.first, stops - 1});
			}
		} 
	}
	return -1;
}

int findCheapestPrice3(int n, vector<vector<int>> flights, int src, int dst, int k) {
	vector<int> c(n, 1e8);
        c[src] = 0;
        
        for(int z=0; z<=k; z++){
            vector<int> C(c);
            for(auto e: flights)
                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
            c = C;
        }
        return c[dst] == 1e8 ? -1 : c[dst];
}

int main() {
	// from to price
	vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
	int src = 0, dst = 3, k = 1;
	cout << findCheapestPrice3(flights.size(), flights, src, dst, k) << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int fact(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

int count_pairs(int N, vector<pair<int, int> > astronauts) {
    int n = astronauts.size();

    vector<vector<int>> adjList(n);

    for (auto i : astronauts) {
        adjList[i.first].push_back(i.second);
        adjList[i.second].push_back(i.first);
    }

    vector<bool> visited(n, 0);
    int ans = n * (n - 1) / 2;

    auto bfs = [&](int source) {

        queue<int> q;
        int count = 0;
        q.push(source);

        visited[source] = true;

        while (!q.empty()) {
            count++;
            int node = q.front(); q.pop();

            for (auto i : adjList[node]) {
                if (!visited[i]) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
        return count;
    };

    vector<int> result;
    for(int i = 0; i < n; i++) {
        int c = bfs(i);
        ans -= c * (c - 1) / 2;
    }


    return ans;
}
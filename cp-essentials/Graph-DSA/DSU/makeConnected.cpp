#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

vector<int> parent, sz;

int find(int x) {
	if(x != parent[x])
		return parent[x] = find(parent[x]);
	return x;
}

void union(int x, int y) {
	int valx = find(x);
	int valy = find(y);
	if(valx == valy)
		return;
	if(sz[valx] > sz[valy])
		swap(valx, valy);
	parent[valx] = valy;
	sz[valy] += sz[valx];
}

long long solve(int n, int m, vector<long long> a, vector<vector<long long>> special) {
	parent = sz = vector<int>(n + 1, 1);
	iota(parent.begin(), parent.end(), 0);
	vector<array<long long, 3>> v;
	long long mini = inf, x;
	for(int i = 0; i < n; i++) {
		if(a[i] < mini) {
			mini = a[i];
			x = i;
		}
	}
	for(int i = 0; i < m; i++) {
		v.push_back({special[i][2], special[i][0], special[i][1]});
	}
	for(int i = 0; i < n; i++) {
		if(x != i)
			v.push_back({a[x] + a[i], x + 1, i + 1});
	}
	sort(v.begin(), v.end());
	long long ans = 0;
	for(int i = 0; i < v.size(); i++) {
		int x1 = v[i][1], y1 = v[i][2];
		if(find(x1) != find(y1)) {
			union(x1, y1);
			ans += v[i][0];
		}
	}
	return ans;
}
#include <bits/stdc++.h>
using namespace std;

int *parent;
int *rank;

void DSU(int n) {
	parent = new int[n];
	rank = new int[n];

	memset(parent, -1, sizeof parent);
	memset(rank, 1, sizeof rank);
}
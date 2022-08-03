#include <bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int> encoded, int first) {
	int n = encoded.size();
	vector<int> res(n);
	res[0] = first;
	for(int i = 0; i < n; i++) {
		res[i + 1] = encoded[i] xor res[i];
	}
	return res;
}
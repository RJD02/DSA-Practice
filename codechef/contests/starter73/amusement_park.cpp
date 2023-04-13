#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if(n == 0) {
		cout << 0;
		return 0;
	}
	vector<long long> v(n);
	for(auto &i: v)
		cin >> i;
	long long max_sum = 0;
	for(int i = 0; i + k <= n; i++) {
		long long temp = 0;
		for(int j = i; j < i + k; j++) {
			temp += v[j];
		}
		if(temp > max_sum)
			max_sum = temp;
	}

	cout << max_sum;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int findOccurrences(int n) {
	vector<int> seq(n + 1, 0);
	unordered_map<int, int> lastSeen;
	for (int i = 0; i < n + 1; i++) {
		if (i == 0) seq[i] = 0;
		else {
			int x = seq[i - 1];
			if (lastSeen.find(x) == lastSeen.end()) {
				seq[i] = 0;
			} else {
				int k = lastSeen[x];
				if (k == i - 1) seq[i] = 0;
				else {
					int j = k;
					while (j < i - 1 and seq[j] != x) {
						j++;
					}
					seq[i] = i - 1 - j;
				}
			}
			lastSeen[x] = i - 1;
		}
	}
	int x = seq[n - 1];
	int count = 0;
	for (int i = 0; i < n; i++) {
		cout << seq[i] << " ";
		if (seq[i] == x) count++;
	}
	cout << endl;
	return count;
}

int main() {
	int n;
	cin >> n;
	cout << findOccurrences(n);
	return 0;
}
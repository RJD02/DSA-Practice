#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr, int n) {
	int low = 0, mid = 0, high = n - 1;
	while (mid <= high) {
		if (arr[mid] == 0) swap(arr[mid++], arr[low++]);
		else if (arr[mid] == 1) mid++;
		else swap(arr[mid], arr[high--]);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &i : v) cin >> i;
	for (auto i : v) cout << i << " ";
	cout << endl;
	sort012(v, n);
	for (auto i : v) cout << i << " ";
	return 0;
}
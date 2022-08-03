#include <bits/stdc++.h>
using namespace std;

int uniqueNumber(vector<int> arr) {
	int ans = arr[0];
	for(int i = 1; i < arr.size(); i++) {
		ans = ans xor arr[i];
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cout << uniqueNumber(arr);
	return 0;
}
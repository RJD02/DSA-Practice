#include <bits/stdc++.h>
using namespace std;

bool CheckSubset(int arr1[], int n1, int arr2[], int n2) {
	unordered_map<int, int> mp;
	for (int i = 0; i < n1; i++) mp[arr1[i]]++;
	for (int j = 0; j < n2; j++) {
		if (mp[arr2[j]] == 0) return false;
		mp[arr2[j]]--;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int n2;
	cin >> n2;
	int arr2[n2];
	for (int i = 0; i < n2; i++) {
		cin >> arr2[i];
	}
	if (CheckSubset(arr, n, arr2, n2))
		cout << "true";
	else
		cout << "false";
}

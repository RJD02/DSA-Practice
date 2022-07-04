#include <bits/stdc++.h>
using namespace std;

int n, target;
int lowest_index, highest_index;

void bsearch(vector<int> v, int low = 0, int high = n - 1) {
	// for(int i = low; i <= high; i++)
	// 	cout << v[i] << " ";
	// cout << endl;
	if(low >= high)
		return;
	int mid = (high + low) / 2;

	if(v[mid] == target) {
		lowest_index = min(mid, lowest_index);
		highest_index = max(mid, highest_index);
		bsearch(v, low, mid - 1);
		bsearch(v, mid + 1, high);
	} 

	if(target > v[mid]) {
		bsearch(v, mid + 1, high);
	} 
	if(target < v[mid]) {
		bsearch(v, low, mid - 1);
	}
}


int findLowestIndex(vector<int> v, int target) {
	int low = 0;
	int high = v.size() - 1;
	int pos = -1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(v[mid] == target) {
			pos = mid;
			high = mid - 1;
		}
		else if(v[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return pos;
}

int findHighestIndex(vector<int> v, int target) {
	int low = 0;
	int high = v.size() - 1;
	int pos = -1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(v[mid] == target) {
			pos = mid;
			low = mid + 1;
		} else if(v[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return pos;

}

void solve() {
	cin >> n >> target;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	// lowest_index = INT_MAX;
	// highest_index = 0;
	// bsearch(v);
	// if(lowest_index == INT_MAX and highest_index == 0)
	// 	cout << -1 << " " << -1 << endl;
	// else
	// 	cout << lowest_index << " " << highest_index << endl;

	int lowest_index = findLowestIndex(v, target);
	int highest_index = findHighestIndex(v, target);
	return {lowest_index, highest_index};
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
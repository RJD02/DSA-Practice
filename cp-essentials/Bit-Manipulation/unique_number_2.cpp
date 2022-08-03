#include <bits/stdc++.h>
using namespace std;

pair<int, int> uniqueNumber(vector<int> arr) {
	int ans = 0;
	for(auto i: arr)
		ans = ans xor i;
	int p = 0;
	while(ans) {
		if(ans & 1)
			break;
		p++;
	}
	int un1 = 0, un2 = 0;
	for(auto i: arr) {
		int pos = p;
		int n = i;
		while(pos) {
			n >>= 1;
			pos--;
		}
		if(n & 1)
			un1 = un1 xor i;
		else
			un2 = un2 xor i;
	}
	return {un1, un2};
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) 
		cin >> arr[i];
	pair<int, int> a = uniqueNumber(arr);
	cout << a.first << " " << a.second;
	return 0;
}
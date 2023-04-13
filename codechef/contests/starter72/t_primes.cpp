#include <bits/stdc++.h>
using namespace std;

bool hasThree(int n) {
	int count = 0;
	for(int i = 2; i * i < n; i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(hasThree(x))
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}

int main() {
	solve();
	return 0;
}
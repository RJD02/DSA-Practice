#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> A) {
	int n = A.size();
	int avg1 = 0;
	for(int i = 0; i < n / 2; i++) {
		avg1 += A[i];
	}
	avg1 = avg1 / (n / 2);
	int avg2 = 0;
	for(int i = n / 2; i < n; i++) {
		avg2 += A[i];
	}
	if(n % 2 == 0)
		avg2 = avg2 / (n / 2);
	else
		avg2 = avg2 / (n / 2 + 1);
	// avg2 = avg2 / (n / 2 + 1);
	cout << avg1 << " " << avg2 << endl;
	int minVal = 0;
	for(int i = 0; i < n; i++) {
		minVal += min(abs(avg1 - A[i]), abs(avg2 - A[i]));
	}
	return minVal;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++)
			cin >> v[i];
		cout << solve(v) << endl;
	}
	
	return 0;
}
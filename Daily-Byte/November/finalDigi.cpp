#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
	if(n / 10 == 0)
		return n;
	int num = 0;
	while(n) {
		num += n % 10;
		n /= 10;
	}
	return solve(num);
}

int main(){
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}
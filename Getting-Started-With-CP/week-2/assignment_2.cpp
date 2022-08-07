/*



There are N boxes. The i-th box a[i] packets of Maggi. So, by picking up the i-th box, you grab a[i] packets of Maggi.

There are Q queries regarding these boxes. For the j-th query you have to answer what is the minimum number of boxes you need to pick up to own at least x[j] packs of Maggi, or print -1 if it's not possible to obtain such a quantity.

In other words, you should print the minimum possible K such that after picking K boxes, you have at least x[j] packets of Maggi. Note that one box can be chosen once only, and queries are independent of each other (you can use the same box for different queries).

Input

The first line of input contains a single integer T (1 ≤ T ≤ 1000)  — the number of test cases. The description of test cases follows.

The first line contains 2 integers N and Q (1 ≤ N , Q ≤  10^5) — the number of boxes and the number of queries you have to print an answer for respectively.

The second line contains N integers a[1], ... , a[n] (1 ≤ a[i] ≤ 10^4) — the number of packs of Maggi in each box.

Then Q lines follow.

Each of the next Q lines contains a single integer x[j] (1≤ x[j] ≤ 10^9) – the number of Maggi packets you want to own for each query.

Output

For each test case output Q lines. For the j-th line output the number of boxes you need to pick up to own at least x[j] packs of Maggi, or print -1 if it's not possible to obtain such a quantity.


Example

Sample Input

3
8 7
4 3 3 1 1 4 5 9
1
10
50
14
15
22
30
4 1
1 2 3 4
3
1 2
5
4
6

output

1
2
-1
2
3
4
8
1
1
-1

*/

#include <bits/stdc++.h>
#define space " "
using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	int sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(int i = 0; i < q; i++) {
		int in; cin >> in;
		if(v[n - 1] > in and sum < in) {
			cout << -1 << endl;
		}
		else {
			int count = 0;
			while(in > 0 and count < n) {
				in -= v[count++];
			}
			if(in > 0)
				cout << -1;
			else
				cout << count;
			cout << endl;
		}
	}
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
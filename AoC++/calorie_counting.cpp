#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int> pq;

	vector<int> v;
	string s;
	while(getline(cin, s)) {
		if(s == "") {
			int sum = accumulate(v.begin(), v.end(), 0);
			pq.push(sum);
			v.resize(0);
		} else {
			v.push_back(stoi(s));
		}
	}
	int arr[3];
	for(int i = 0; i < 3; i++) {
		arr[i] = pq.top();
		pq.pop();
	}
	cout << accumulate(arr, arr + 3, 0);
	return 0;

}

void hello() {
	cout << "Hello world" << endl;
}


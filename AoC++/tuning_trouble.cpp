#include <bits/stdc++.h>
using namespace std;

int first() {
	string line;
	cin >> line;
	// cout << line;
	int i = 0;
	
	for(i = 0; i < line.size() - 14; i++) {
		set<char> st;
		int j = i;
		while(st.find(line[j]) == st.end() and st.size() < 15 and j - i < 14)
			st.insert(line[j]), j++;
		if(st.size() == 14)
			break;
	}
	return i + 14;
}

int main() {
	cout << first();
	return 0;
}
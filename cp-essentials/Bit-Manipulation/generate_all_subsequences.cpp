#include <bits/stdc++.h>
using namespace std;

void overLayNumber(char arr[], int num) {
	int j = 0;
	while(num) {
		int last_bit = num & 1;
		if(last_bit)
			cout << arr[j];
		j++;
		num = num >> 1;
	}
	cout << endl;
}

void generateAllSubsequences(char arr[]) {
	int n = strlen(arr);
	for(int i = 0; i < (1 << n); i++) 
		overLayNumber(arr, i);
	
}


int main() {
	char arr[1000];
	cin >> arr;
	generateAllSubsequences(arr);
	return 0;
}
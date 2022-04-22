#include <bits/stdc++.h>
using namespace std;

char *mystrtok(char *str, char dlim) {
	static char *input = NULL;
	if (str != NULL) {
		input = str;
	}
	if (input == NULL)
		return NULL;
	char *token = new char[strlen(input + 1)]; // We can return a dynamic array but not a static one
	int i = 0;
	for(; input[i] != '\0'; i++) {
		if (input[i] != dlim) {
			token[i] = input[i];
		} else {
			token[i] = '\0';
			input = input + i + 1;
			return token;
		}
	}
	// out of the loop
	token[i] = '\0';
	// reset the input as NULL
	input = NULL;
	return token;
}

int main() {
	char s[1000];
	cin.getline(s, 1000);
	char *token = mystrtok(s, ' ');
	while(token != NULL) {
		cout << token << endl;
		token = mystrtok(NULL, ' ');
	}
	return 0;
}
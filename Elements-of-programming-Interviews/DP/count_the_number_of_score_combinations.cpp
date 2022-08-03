#include <bits/stdc++.h>
using namespace std;

int numCombinationsForFinalScore(int final_score, vector<int> &play_scores) {
	vector<vector<int>> num_combinations(play_scores.size(), vector<int>(final_score + 1, 0));
	for(int i = 0; i < (int)play_scores.size(); i++) {
		num_combinations[i][0] = 1;
		for(int j = 1; j <= final_score; j++) {
			int without_this_play = 1 >= 1 ? num_combinations[i - 1][j] : 0;
			int with_this_play = j >= play_scores[i] ? num_combinations[i][j - play_scores[i]] : 0;
			num_combinations[i][j] = without_this_play + with_this_play;
		}
	}
	return num_combinations.back().back();
}

int main() {
	int final_score, n;
	cin >> final_score >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	cout << numCombinationsForFinalScore(final_score, v) << endl;
}

/*
This question is asked by Amazon. Given an
integer array, two players take turns picking
the largest number from the ends of the array.
First, player one picks a number (either the left
end or right end of the array) followed by player
two. Each time a player picks a particular numbers,
it is no longer available to the other player.
This picking continues until all numbers in the array
have been chosen. Once all numbers have been picked,
the player with the larger score wins. Return whether
or not player one will win.
Note: You may assume that each player is playing to
win (i.e. both players will always choose the maximum of t
he two numbers each turn) and that there will always
be a winner.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int left = 0, right = n - 1;
	int player1, player2;
	int currPlay = 0;
	// 0 => 1st player, 1 => 2nd player
	player2 = player1 = 0;

	while (left <= right) {
		if (currPlay % 2 == 0) {
			if (arr[left] < arr[right]) {
				player1 += arr[right--];
			} else {
				player1 += arr[left++];
			}
		} else {
			if (arr[left] < arr[right]) {
				player2 += arr[right--];

			} else {
				player2 += arr[left++];
			}
		}
		currPlay++;
	}
	// cout << player2 << " " << player1 << endl;
	cout << (player1 > player2) << endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while (n--)
		solve();
	return 0;
}
/*

Ankita and Biswas are playing a turn-based game, which is to say that if Ankita makes the first move, then Biswas makes the second move, and so on (with Ankita playing all the odd-numbered turns and Biswas playing the even-numbered ones); while if Biswas makes the first move, then Ankita makes the second move, and so on (with Biswas playing all the odd-numbered turns and Ankita playing the even-numbered ones).

Ankita has a collection of 𝑛 cards, the 𝑖-th of them has the integer 𝑎[𝑖] written on it. Biswas has a collection of 𝑚 cards, the 𝑗-th of them has the integer 𝑏[𝑗] written on it.

On each turn of the game, the player whose turn it is will discard one of the cards in their collection. After the first turn, for the move to be valid, the number on the card has to be greater than the card discarded by the other player in the previous turn. 

If some player cannot make a turn, he/she loses.

For example, if Ankita has 4 cards with numbers [10,5,13,8], and Biswas has 3 cards with numbers [6,15,6], the game may go as follows:

Ankita can choose any of her cards. She chooses the card with integer 5 and plays it.
Biswas can choose any of his cards with number greater than 5. He chooses a card with integer 6 and plays it.
Ankita can choose any of her cards with number greater than 6. She chooses the card with integer 10 and plays it.
Biswas can choose any of his cards with number greater than 10. He chooses a card with integer 15 and plays it.
Ankita can choose any of her cards with number greater than 15, but she has no such cards, so she loses.

Both Ankita and Biswas play optimally (if a player is able to win the game no matter how the other player plays, the former player will definitely win the game).

You have to answer two questions:

who wins if Ankita is the first player?
who wins if Biswas is the first player?

Input

The first line contains one integer 𝑡 (1≤𝑡≤1000) — the number of test cases. Each test case consists of four lines.

The first line of a test case contains one integer 𝑛 (1≤𝑛≤50) — the number of cards Ankita has.

The second line contains 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛 (1≤𝑎[𝑖]≤50) — the numbers written on the cards that Ankita has.

The third line contains one integer 𝑚 (1≤𝑚≤50) — the number of Biswas's cards.

The fourth line contains 𝑚 integers 𝑏1,𝑏2,…,𝑏𝑚 (1≤𝑏[𝑖]≤50) — the numbers on Biswas's cards.

Output
For each test case, print two lines. The first line should be Ankita if Ankita wins when she is the first player; otherwise, the first line should be Biswas. The second line should contain the name of the winner if Biswas is the first player, in the same format.

Example

Sample input

4
1
6
2
6 8
4
1 3 3 7
2
4 2
1
50
2
25 50
10
1 2 3 4 5 6 7 8 9 10
2
5 15

Sample output

Biswas
Biswas
Ankita
Ankita
Ankita
Biswas
Biswas
Biswas

*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	vector<int> b(m);
	for(int i = 0; i < m; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if(a[n - 1] > b[m - 1])
		cout << "Ankita" << endl << "Ankita" << endl;
	else if(a[n - 1] < b[m - 1])
		cout << "Biswas" << endl << "Biswas" << endl;
	else
		cout << "Ankita" << endl << "Biswas" << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
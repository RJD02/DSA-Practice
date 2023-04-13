#include <bits/stdc++.h>
using namespace std;

class Player {
	string name;
	char symbol;
public:
	Player() {}
	Player(string n, char s) {
		name = n;
		symbol = s;
	}
	void setSymbol(char s) {
		symbol = s;
	}
	void setName(string n) {
		name = n;
	}
	char getSymbol() {
		return symbol;
	}
	string getName() {
		return name;
	}
};

class Board {
	char board[3][3];
	int n = 3;
public:
	Board() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = ' ';
			}
		}
	}
	void addSymbol(int i, int j, char symbol) {
		if (i < 0 or i >= n or j < 0 or j >= n) return;
		if (i < 3 and j < 3) {
			board[i][j] = symbol;
		}
	}
	bool checkWin(char symbol) {
		bool rowAns = false;
		for (int i = 0; i < n; i++) {
			bool ans = true;
			for (int j = 0; j < n; j++) {
				if (board[i][j] != symbol) ans = false;
			}
			rowAns |= ans;
		}
		bool colAns = false;
		for (int i = 0; i < n; i++) {
			bool ans = true;
			for (int j = 0; j < n; j++) {
				if (board[j][i] != symbol) ans = false;
			}
			colAns |= ans;
		}
		bool rightDiagonalAns = true;
		for (int i = 0; i < n; i++) {
			if (board[i][i] != symbol) rightDiagonalAns = false;
		}
		bool leftDiagonalAns = true;
		for (int i = 0; i < n; i++) {
			if (board[i][n - i] != symbol) leftDiagonalAns = false;
		}
		bool ans = rowAns or colAns or rightDiagonalAns or leftDiagonalAns;
		return ans;
	}
	void printBoard() {
		for (int i = 0 ; i < n; i++) {
			cout << "| ";
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << "| ";
			}
			cout << endl;
		}
	}
	bool isFilled(char s1, char s2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] != s1 and board[i][j] != s2)
					return false;
			}
		}
		return true;
	}
};


class Game {
	Player p1, p2;
	Board b;
	bool turn;
public:
	void init() {
		string name1, name2;
		char symbol1, symbol2;
		cout << "Enter the name of player 1: ";
		cin >> name1;
		cout << "Enter the symbol of player 1: ";
		cin >> symbol1;
		cout << "Enter the name of player 2: ";
		cin >> name2;
		cout << "Enter the symbol of player 2: ";
		cin >> symbol2;
		p1 = Player(name1, symbol1);
		p2 = Player(name2, symbol2);
	}
	void play() {
		init();
		int i, j;
		char symbol;
		do {
			if (turn) {
				cout << "Player 1 - " << p1.getName() << "'s turn" << endl;
				cout << "Enter coordinates: ";
				cin >> i >> j;
				symbol = p1.getSymbol();
			} else {
				cout << "Player 2 - " << p2.getName() << "'s turn" << endl;
				cout << "Enter coordinates: ";
				cin >> i >> j;
				symbol = p2.getSymbol();
			}
			b.addSymbol(i, j, symbol);
			b.printBoard();
			turn = !turn;
		} while (!b.checkWin(symbol) and !b.isFilled(p1.getSymbol(), p2.getSymbol()));
		if (b.isFilled(p1.getSymbol(), p2.getSymbol())) {
			cout << "It's a draw" << endl;
			return;
		} else {
			if (turn) {
				cout << "Player 2 - " << p2.getName() << " wins" << endl;
			} else {
				cout << "Player 1 - " << p1.getName() << " wins" << endl;
			}
		}
	}
};

int main() {
	Game g;
	g.play();
	return 0;
}
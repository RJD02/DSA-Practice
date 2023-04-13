#include <bits/stdc++.h>
using namespace std;

enum Color {
	BLACK = 1,
	WHITE = 2,
	BLANK = 0,
};

// class Player {
// 	string name;
// 	Color color;
// public:
// 	Player(string n, int color) {
// 		name = n;
// 		color = BLACK;
// 	}
// 	Player() {}
// 	void setName(string n) {
// 		name = n;
// 	}
// 	string getName() {
// 		return name;
// 	}
// 	// friend class Board;
// };

typedef pair<int, int> pii;

class Board {
	const int n = 8;
	int board[8][8];
	vector<pii> directions;
public:
	Board() {
		directions = {{0, 1}, {1, 0}, { -1, 0}, {0, -1}, { -1, -1}, {1, -1}, { -1, 1}, {1, 1}};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n ; j++)
				board[i][j] = 0;
		}
		board[3][3] = BLACK;
		board[3][4] = WHITE;
		board[4][3] = WHITE;
		board[4][4] = BLACK;
	}

	inline bool isInside(int i, int j) {
		return i >= 0 and i < n and j >= 0 and j < n;
	}

	bool dfs(vector<pii> &path, int i, int j, int incI, int incJ, int searchColor) {
		if (isInside(i, j)) {
			if (board[i][j] == 0) return false;
			if (board[i][j] != searchColor) return true;
			path.push_back({i, j});
			return dfs(path, i + incI, j + incJ, incI, incJ, searchColor);
		}
		return false;
	}

	void printBoard() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}

	void flip(vector<pii> &path, int fillColor) {
		// cout << "path: ";
		for (auto i : path) {
			board[i.first][i.second] = fillColor;
			// cout << i.first << " " << i.second << endl;
		}
	}

	bool move(int i, int j, int fillColor, int searchColor) {
		if (!isInside(i, j)) return false;
		board[i][j] = searchColor;
		int numFlips = 0;
		vector<vector<pii>> res;
		for (auto d : directions) {
			vector<pii> path;
			// path.push_back({i, j});
			bool ans = dfs(path, i + d.first, j + d.second, d.first, d.second, searchColor);

			// flip(path, fillColor);
			if (ans)  {
				res.push_back(path);
				numFlips += path.size();
			}
		}
		for (auto i : res) flip(i, fillColor);
		if (numFlips == 0) {
			board[i][j] = 0;
			return false;
		}
		board[i][j] = fillColor;
		return true;

	}

	vector<int> getStatus() {
		vector<int> count(3);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				count[board[i][j]]++;
			}
		}
		return count;
	}

	bool isFilled() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 0) return false;
			}
		}
		return true;
	}
};

class Othello {
	const Color p1 = BLACK, p2 = WHITE;
	Board b;
	bool turn = true;
public:
	bool move(int i, int j) {

		if (b.isFilled()) return false;
		bool ans;
		if (turn) {
			ans = b.move(i, j, p1, p2);
		} else {
			ans = b.move(i, j, p2, p1);
		}
		if (ans) {
			turn = !turn;
			b.printBoard();
			return true;
		}
		return false;
	}
};

int main() {
	Othello o;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (!o.move(x, y)) {
			cout << "false" << endl;
			i--;
		}
	}
	return 0;
}
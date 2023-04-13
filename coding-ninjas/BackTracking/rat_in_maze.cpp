#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, { -1, 0}, {0, -1}};

bool ratInAMaze(int maze[][20], int n) {
  queue<pair<int, int>> q;
  q.push({0, 0});
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  visited[0][0] = true;
  while (!q.empty()) {
    auto x = q.front(); q.pop();
    cout << maze[x.first][x.second] << " ";
    if (x.first == n - 1 and x.second == n - 1) return true;
    for (auto y : directions) {
      pair<int, int> curr = {x.first + y.first, x.second + y.second};
      if (curr.first < n and curr.first >= 0 and curr.second < n and curr.second >= 0) {
        if (maze[curr.first][curr.second] == 1 and !visited[curr.first][curr.second]) {
          visited[curr.first][curr.second] = true;
          q.push({curr.first, curr.second});
        }
      }
    }
  }
  return false;
}

int main() {

  int n;
  cin >> n ;
  int maze[20][20];
  for (int i = 0; i < n ; i++) {
    for (int j = 0; j < n; j++) {
      cin >> maze[i][j];
    }
  }
  if (ratInAMaze(maze, n))
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }
}

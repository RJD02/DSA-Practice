#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        int freshOranges = 0;
        int mins = -1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                if(grid[i][j] == 1)
                    freshOranges++;
            }
        }
        
        auto isInside = [=] (int i, int j) {
            return i >= 0 and i < n and j >= 0 and j < m;
        };
        
        vector<pair<int, int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        int length = q.size();
        while(!q.empty()) {
            auto i = q.front(); q.pop();
            length--;
            for(auto d : directions) {
                int x = i.first + d.first, y = i.second + d.second;
                if(isInside(x, y) and grid[x][y] == 1) {
                    --freshOranges;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
            if(length == 0) {
                mins++;
                length = q.size();
            }
        }
        if(freshOranges > 0)
            return -1;
        return max(mins, 0);
    }

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}
	cout << orangesRotting(grid);
}
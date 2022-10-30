#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

	bool canPlace(vector<int> base, vector<int> toPlace) {
		if(base[0] >= toPlace[0] and base[1] >= toPlace[1] and base[2] >= toPlace[2])
			return true;
		return false;
	}

    int maxHeight(vector<vector<int>>& cuboids) {
    	int n = cuboids.size();
        for(int i = 0; i < n; i++) {
        	sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<int> dp(n);
        for(int i = 0; i < n; i++)
        	dp[i] = cuboids[i][2];
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < i; j++) {
        		if(canPlace(cuboids[i], cuboids[j])) {
        			if(cuboids[i][2] + dp[j] > dp[i])
        				dp[i] = cuboids[i][2] + dp[j];
        		}
        	}
        }

        return *max_element(dp.begin(), dp.end());
    }
};
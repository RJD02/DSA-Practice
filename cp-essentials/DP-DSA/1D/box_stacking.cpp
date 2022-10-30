#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    static bool cuboidCmp(vector<int> a, vector<int> b) {
        return a[2] < b[2];
    }
    
    static bool canPlace(vector<int> base, vector<int> boxToPlace) {
        if(base[0] > boxToPlace[0] and base[1] > boxToPlace[1] and base[2] > boxToPlace[2])
            return true;
        return false;
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        sort(cuboids.begin(), cuboids.end(), cuboidCmp);
        int n = cuboids.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++)
            dp[i] = cuboids[i][2];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(canPlace(cuboids[i], cuboids[j]))
                    if(cuboids[i][2] + dp[j] > dp[i])
                        dp[i] = cuboids[i][2] + dp[j];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
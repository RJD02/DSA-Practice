class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if(mp.find(val) == mp.end()) {
                mp[target - val] = i;
            } else {
                return {i, mp[val]};
            }
        }
        return {-1, -1};
    }
};
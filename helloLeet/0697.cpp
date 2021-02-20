// Degree of an array 
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int iter = 0; iter < nums.size(); ++iter) {
            if (mp.find(nums[iter]) == mp.end()) {
                mp[nums[iter]] = {1, iter, iter};
            } else {
                ++mp[nums[iter]][0];
                mp[nums[iter]][2] = iter;
            }
        }
        int mx_cnt = 0, mn_len = 0;
        for(auto& [_, v] : mp) {
            if (v[0] > mx_cnt) {
                mx_cnt = v[0];
                mn_len = v[2] - v[1] + 1;
            } else if (v[0] == mx_cnt && v[2] - v[1] + 1 < mn_len) {
                mn_len = v[2] - v[1] + 1;
            }
        }
        return mn_len;
    }
};

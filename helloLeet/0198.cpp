//very classic dp

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = nums.size();
        if (l == 1) return nums[0];
        int dp[l];
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < l; i ++) dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        return dp[l - 1];
    }
};

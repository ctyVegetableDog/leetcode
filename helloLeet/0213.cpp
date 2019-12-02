//simplify this ques to two house robber ques 1.0 to n-1 2. 1 to n

class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size(), res;
        if (l == 0) return 0;
        if (l == 1) return nums[0];
        if (l == 2) return max(nums[0], nums[1]);
        if (l == 3) return max(nums[0], max(nums[1], nums[2]));
        int dp[l];
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < l - 1; i++) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        res = dp[l - 2];
        memset(dp, 0, sizeof(dp));
        dp[1] = nums[1];
        dp[2] = max(dp[1], nums[2]);
        for (int i = 3; i < l; i++) dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return max(res, dp[l - 1]);
    }
};

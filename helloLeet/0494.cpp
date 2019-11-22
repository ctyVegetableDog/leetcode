//very impressive ques, Math and dp
//solution is too long, so watch the webpage

class Solution {
public:
    int getRes(vector<int>& nums, int S) {
        vector<int> dp(S + 1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int i = S; i >= n; i--) dp[i] += dp[i - n];
        }
        return dp[S];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sm = accumulate(nums.begin(), nums.end(), 0);
        return sm < S || (S + sm) & 1 ? 0 : getRes(nums, (S + sm) >> 1);
    }
};

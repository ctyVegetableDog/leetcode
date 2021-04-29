// can cross (dp)
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int len = stones.size();
        vector<vector<bool>> dp(len, vector<bool>(len));
        dp[0][0] = true;
        for (int i = 1; i < len; ++i) {
            if (stones[i] - stones[i - 1] > i) return false;
        }
        for (int i = 1; i < len; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k > j + 1) break;
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == len - 1 && dp[i][k]) return true;
            }
        }
        return false;
    }
};

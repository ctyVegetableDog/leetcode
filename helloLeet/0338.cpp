//dp

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) return {0};
        vector<int> dp(num + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        int k = 2;
        while (k <= num) {
            for (int i = k; i < 2 * k; i ++) {
                if (i == num + 1) return dp;
                if (i < (3 * k)/2) dp[i] = dp[i - k/2];
                else dp[i] = dp[i - k] + 1;
            }
            k *= 2;
        }
        return dp;
    }
};

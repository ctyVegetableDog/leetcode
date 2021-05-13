// numWays (dp)
class Solution {
private:
    const int MODULO = 1000000007;
public:
    int numWays(int steps, int arrLen) {
        int maxPos = min(steps, arrLen - 1);
        vector<vector<int>> dp(steps + 1, vector<int>(maxPos + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j <= maxPos; ++j) {
                dp[i][j] = dp[i - 1][j];    //stay
                if (j - 1 >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MODULO;  //move on
                }
                if (j + 1 <= maxPos) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MODULO;  //back
                }
            }
        }
        return dp[steps][0];
    }
};

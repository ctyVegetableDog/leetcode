//champagne Tower (how to use a vector to store 2D dp matrix)

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> dp(101, 0);
        dp[0] = poured;
        for (int i = 1; i <= query_row; i++) {
            for (int j = i; j >= 0; j--) 
                dp[j + 1] += dp[j] = max(0.0, (dp[j] - 1.0) / 2.0);
        }
        return min(dp[query_glass],1.0);
    }
};

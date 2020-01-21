//ugly number2

/*
	dp[n] not only means the nth ugly number, but also means, the number of (2, 3, 5) have to be calculate next time
	dp[n] = min(dp[t2] * 2, dp[t3] * 3, dp[t5] * 5)
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> dp(n, -1);
        dp[0] = 1;
        for (int i = 1; i < n; i ++) {
            dp[i] = min(dp[t2] * 2, min(dp[t3] * 3, dp[t5] * 5));
            if (dp[i] == dp[t2] * 2) t2++;
            if (dp[i] == dp[t3] * 3) t3++;
            if (dp[i] == dp[t5] * 5) t5++;
        }
        return dp[n - 1];
    }
};

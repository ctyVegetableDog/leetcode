// 多米诺和托米诺平铺

class Solution {
public:
    // 相当难想的一道状态dp
    // 考虑dp[i]为i列之前列都被铺满，第i列之后还没开始铺的情况，显然此时第i列有4种可能
    // 1. 空的 2.上方格子有下方空 3.上方空下方有 4.被铺满 可用4种状态分别表示
    // 1.dp[i][0]表示全空，此时该状态直接等价于第i - 1列全铺满，即dp[i][0] = dp[i - 1][3]
    // 2.dp[i][1]上满下空，此时有两种可能1. 第[i - 1]列本来为空，然后用了一个 “「 ”符号，或第[i - 1]列本来是上空下满，在上面有了个横的Domino tile，即dp[i][1] = dp[i - 1][0](为空) + dp[i - 1][2](上空下满)
    // 3.dp[i][2]上空下满，和上满下空同理，但是都反过来dp[i][2] = dp[i - 1][0] + dp[i - 1][1]
    // 4.dp[i][3]都满，此时有4种可能，dp[i - 1]全空，然后用两个横Domino，dp[i - 1]上空或下空，用一个Tromino，dp[i - 1]全满，用一个竖Domino，即dp[i][3] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]
    int numTilings(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(4));
        dp[0][3] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        return dp[n][3];
    }
private:
    const long long mod = 1e9 + 7;
};

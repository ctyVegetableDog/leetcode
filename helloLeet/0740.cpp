//delete and earn (dp)

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxn = -1;
        for (int i : nums) {
            maxn = max(i, maxn);
        }
        int newnum[maxn + 1];
        memset(newnum, 0, sizeof(newnum));
        newnum[0] = 0;
        for(int i : nums) {
            ++newnum[i];
        }
        int dp[maxn + 1];
        dp[0] = 0;
        dp[1] = newnum[1];
        for (int i = 2; i <= maxn; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + i * newnum[i]);
        }
        return dp[maxn];
    }
};

//longest palindromic subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.size();
        int dp[l][l] = {0};
        for (int i = l - 1; i >= 0; i --) {
            dp[i][i] = 1;
            for (int j = i + 1; j < l; j ++) dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] + 2 : max(dp[i + 1][j], dp[i][j - 1]);
         }
        return dp[0][l - 1];
    }
};

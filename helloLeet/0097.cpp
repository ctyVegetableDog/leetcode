// 交错字符串

/*
 *滚动数组优化dp数组空间
 * */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len3 != len1 + len2) return false;
        vector<bool> dp(len2 + 1, false);
        dp[0] = true;
        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                int k = i + j;
                if (i > 0) dp[j] = (dp[j] && s3[k - 1] == s1[i - 1]);
                if (j > 0 && dp[j - 1] && s3[k - 1] == s2[j - 1]) dp[j] = true;
            }
        }
        return dp[len2];
    }
};

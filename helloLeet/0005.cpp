//dp, but it's not the best solution

class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") return "";
        bool dp[1005][1005];
        int l = s.length();
        int resi = 0, resj = 0;
        for (int i = 0; i < l - 1; i ++) {
            dp[i][i] = true;
            dp[i][i + 1] = (s[i] == s[i + 1]);
        }
        dp[l -1] [l - 1] = true;
        for (int j = 1; j < l; j++)
            for (int i = j - 1; i >= 0; i --) {
                if (j - i > 1)
                    dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
                if (dp[i][j] && j - i > resj - resi){
                    resi = i;
                    resj = j;
                }
            }
        return s.substr(resi, resj - resi + 1);
    }
};

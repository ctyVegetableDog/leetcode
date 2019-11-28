//Palindromic substrings (classical dp)

class Solution {
public:
    int countSubstrings(string s) {
        int l = s.size(), res = 0;
        int dp[l][l];
        for (int i = l - 1; i >= 0; i --) {//as we need use dp[i + 1] to get dp[i], so it should be in decreasing order
            for (int j = i; j < l; j++) {
                dp[i][j] = (s[i] == s[j]) && (j - i < 3 || dp[i + 1][j - 1]);
                if (dp[i][j]) res++;
            }
        }
        return res;
    }
};

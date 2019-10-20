//dp

class Solution {
public:
    int numDecodings(string s) {
        int l = s.length();
        int dp[l+1];
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        for(int i = 2; i <= l; i++){
            if (s[i - 1] == '0' && (s[i - 2] > '2' || s[i - 2] == '0')) return 0;
            else if(s[i - 1] == '0' && (s[i - 2] == '1' || s[i - 2] == '2')) 
                dp[i] = dp[i - 2];
            else if(s[i - 1] != '0' && s[i - 2] == '0')
                dp[i] = dp[i - 1];
            else if ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp[l];
    }
};

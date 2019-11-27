//regular expression matching (very good dp ques)

class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.length(), pl = p.length();
        vector<vector<int> > dp(sl + 1, vector<int>(pl + 1, -1));
        return bool(getDP(s, p, 0, 0, dp));
    }
    int getDP(string s, string p, int i, int j, vector<vector<int> >& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        bool ans;
        if (j == p.length()) ans = i == s.length();
        else {
            bool match = i < s.length() && (s[i] == p[j] || p[j] == '.');
            if (j < p.length() - 1 && p[j + 1] == '*') ans = (bool(getDP(s, p, i, j + 2, dp)) || match && bool(getDP(s, p, i + 1, j, dp)));
        else ans = match && bool(getDP(s, p, i + 1, j + 1, dp));
        }
        dp[i][j] = int(ans);
        return int(ans);
    }
};

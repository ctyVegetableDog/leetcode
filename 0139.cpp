//dp

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for (string eachWord: wordDict) st.insert(eachWord);
        int l = s.length();
        bool dp[l];
        for (int i = 0; i < l; i++) dp[i] = false;
        dp[0] = (st.find(s.substr(0,1))!=st.end());
        for (int i = 1; i < l; i++) {
            if(st.find(s.substr(0,i + 1)) != st.end()) {
                dp[i] = true;
                continue;
            }
            for (int j = 1; j <= i; j++) {
                if (dp[i -j] && (st.find(s.substr(i - j + 1,j)) != st.end())) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[l-1];
    }
};

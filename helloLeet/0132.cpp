// Split Palindrome 2
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pa(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                pa[i][j] = (s[i] == s[j]) && pa[i + 1][j - 1];
            }
        }
        vector<int> res(n, INT_MAX);
        res[0] = 0;
        for (int i = 1;i < n; ++i) {
            if (pa[0][i]) res[i] = 0;
            else {
                for (int j = 0; j < i; ++j) {
                    if (pa[j + 1][i]) res[i] = min(res[i], res[j] + 1);
                }
            }
        }
        return res[n - 1];
    }
};

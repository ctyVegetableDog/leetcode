// maxSumSubmatrix
// prefix + bs
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        bool chooseM = (m > n);
        int ans = INT_MIN;
        for (int top = 1; top <= (chooseM ? n : m); ++top) {
            for (int bot = top; bot <= (chooseM ? n : m); ++bot) {
                set<int> st;
                st.insert(0);
                for (int c = 1; c <= (chooseM ? m : n); ++c) {
                    int subpre = chooseM ? (pre[c][bot] - pre[c][top - 1]) : (pre[bot][c] - pre[top - 1][c]);
                    auto target = st.lower_bound(subpre - k);
                    if (target != st.end()) {
                        ans = max(ans, subpre - *target);
                    }
                    st.insert(subpre);
                }
            }
        }
        return ans;
    }
};

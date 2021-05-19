// kthLargestValue
// prefix / partial sort
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pre(m + 1, vector<int>(n + 1));
        vector<int> res;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre[i][j] = pre[i - 1][j] ^ pre[i][j - 1] ^ pre[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                res.push_back(pre[i][j]);
            }
        }
        nth_element(res.begin(), res.begin() + k - 1, res.end(), greater<int>());
        return res[k - 1];
    }
};

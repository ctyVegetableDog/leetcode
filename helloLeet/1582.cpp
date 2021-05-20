// num special
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
         int n = mat.size(), m = mat[0].size(), res = 0;
         vector<int> col_sum(m), line_sum(n);
         for (int i = 0; i < n; ++i) {
             for (int j = 0;j < m; ++j) {
                 col_sum[j] += mat[i][j];
                 line_sum[i] += mat[i][j];
             }
         }
         for (int i = 0; i < n; ++i) {
             for (int j = 0; j < m; ++j) {
                 if (mat[i][j] == 1 && col_sum[j] == 1 && line_sum[i] == 1) ++res;
             }
         }
         return res;
    }
};

// 零矩阵

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int n = matrix.size(), m = matrix[0].size();
        bool flag_col = false, flag_row = false;
        for (int i = 0; i < n; ++i) if (matrix[i][0] == 0) flag_col = true;
        for (int j = 0; j < m; ++j) if (matrix[0][j] == 0) flag_row = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < n; ++i) if (flag_col) matrix[i][0] = 0;
        for (int j = 0; j < m; ++j) if (flag_row) matrix[0][j] = 0;
        return;
    }
};

// Toeplitz matrix

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = matrix.size() - 1; i >= 0; --i) {
            for (int j = 0; i + j < matrix.size() && j < matrix[0].size(); ++j) {
                if (matrix[i + j][j] != matrix[i][0]) return false;
            }
        }
        for (int i = 1; i < matrix[0].size(); ++i) {
            for (int j = 0; j < matrix.size() && i + j < matrix[0].size(); ++j) {
                if (matrix[j][i + j] != matrix[0][i]) return false;
            }
        }
        return true;
    }
};

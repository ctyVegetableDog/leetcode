// transpose matrix
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int x = matrix.size(), y = matrix[0].size();
        vector<vector<int>> res(y, vector<int>(x, 0));
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                res[j][i] = matrix[i][j];
            }
        }
        return res;
    }
};

//set (use space exchange time)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        if (matrix[0].empty()) return;
        set<int> icheck;
        set<int> jcheck;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == 0) {
                    icheck.insert(i);
                    jcheck.insert(j);
                }
            }
        }
        for (int i : icheck) for (int j = 0; j < n; j++) matrix[i][j] = 0;
        for (int j : jcheck) for (int i = 0; i < m; i++) matrix[i][j] = 0;
    }
};

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

//best method time O(n*m) space O(1) (using the first element to save whether this col/line have to be updated)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        if (matrix[0].empty()) return;
        bool ok = false;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i ++) {
            if (matrix[i][0] == 0) ok = true;
            for (int j = 1; j < n; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j ++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
        }
        if (ok)
            for (int i = 0;i < m; i++) matrix[i][0] = 0;
    }
};

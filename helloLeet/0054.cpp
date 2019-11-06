//just logic

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        if (matrix[0].empty()) return res;
        int dr = 0, m = matrix[0].size(), n = matrix.size();//0 right 1 down 2 left 3 up
        int r = m - 1, d = n - 1, l = 0, u = 0;//margins
        int i = 0, j = 0;
        while (l <= r && u <= d) {
            res.push_back(matrix[j][i]);
            if (dr == 0) {
                if (i == r) {
                    dr = 1;
                    j ++;
                    u ++;
                } else {
                    i++;
                }
            } else if (dr == 1) {
                if (j == d) {
                    dr = 2;
                    i--;
                    r--;
                } else {
                    j++;
                }
                
            } else if (dr == 2) {
                if (i == l) {
                    dr = 3;
                    j--;
                    d--;
                } else {
                    i--;
                }
            } else {
                if (j == u) {
                    dr = 0;
                    i++;
                    l++;
                } else {
                    j--;
                }
            }
        }
        return res;
    }
};

//totally as 0053

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res (n, vector<int> (n, 0));
        int i = 0, j = 0, t = 1, l = 0, r = n - 1, u = 0, d = n - 1;
        int dr = 0;////0 right 1 down 2 left 3 up
        while (l <= r && u <= d) {
            res[j][i] = t;
            t++;
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

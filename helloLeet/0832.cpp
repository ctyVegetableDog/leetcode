// flip over image
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int len = A.size();
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < (len + 1) / 2; ++j) {
                int temp = A[i][len - j - 1];
                A[i][len - j - 1] = 1 - A[i][j];
                A[i][j] = 1 - temp;
            }
        }
        return A;
    }
};

//swap in matrix

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int s = matrix.size();
        int n = s/2;
        for (int i = 0; i <= n; i++) {
            for (int j = i; j < s - i- 1; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[s-1-j][i];
                matrix[s-1-j][i] = matrix[s-1-i][s-1-j];
                matrix[s-1-i][s-1-j] = matrix[j][s-1-i];
                matrix[j][s-1-i] = t;
            }
        }
    }
};

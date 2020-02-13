//Range Sum Query 2D - Immutable (dp)

/*
	dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1]
*/

class NumMatrix {
private:
    vector<vector<int> > matrix;
    vector<vector<int> > dp;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        int r = matrix.size(), c = (r != 0) ? matrix[0].size() : 0;
        dp = vector<vector<int>>(r + 1, vector<int>(c + 1, 0));
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <=c; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    
    /*
        (a,b,c,d)
        (0,0,c,d) - (0, 0, a - 1,d) - (0, 0, c, b - 1) + (0, 0, a - 1, b - 1)
    */
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

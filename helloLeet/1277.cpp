//Count Square Submatrices with All Ones (dp)

/*
	Just the same question as 0221
	dp[i][j] means the largest square whose bottom right corner is matrix[i - 1][j - 1]
	the square[i][j]'s area could be extended only when all of [i - 1][j], [i][j - 1] and [i - 1][j - 1] is large eough, for instance:
	0 1 1 1 0
	1 1 1 1 0
	as all of dp[0][1], [0][2] and [1][1] is 1, dp[1][2] will become 2
	0 1 1 1 0
	1 1 2 2 0
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int res = 0, lines = matrix.size();
        if (lines == 0) return 0;
        int cols = matrix[0].size();
        vector<vector<int> > dp(lines + 1, vector<int>(cols + 1, 0));
        for (int i = 1; i <= lines; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (matrix[i - 1][j - 1] == 1) {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    res += dp[i][j];
                }
            }
        }
        return res;
    }
};

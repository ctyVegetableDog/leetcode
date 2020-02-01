//Maximal square

/*
	space-opt for dp
	use vector present 2D matrix
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size(), col = row > 0 ? matrix[0].size() : 0;
        vector<int> dp(col + 1, 0);
        int res = 0, prev = 0;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                int temp = dp[j];//dp[i - 1][j]
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    res = max(res, dp[j]);
                } else dp[j] = 0;
                prev = temp;//compare to next j, temp became j - 1, so prev meansdp[i - 1][j - 1]
            }
        }
        return res * res;
    }
};

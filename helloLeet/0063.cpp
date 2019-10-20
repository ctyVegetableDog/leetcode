//dp

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long long dp[m][n];
        bool ok = true;
        for (int i = 0; i < m; i++) {
            if (ok){
                if (obstacleGrid[i][0] == 1) {
                    dp[i][0] = 0;
                    ok = false;
                }
                else dp[i][0] = 1;
            }
            else dp[i][0] = 0;
        }
        ok = true;
        for (int i = 0; i < n; i++) {
            if (ok){
                if (obstacleGrid[0][i] == 1) {
                    dp[0][i] = 0;
                    ok = false;
                }
                else dp[0][i] = 1;
            }
            else dp[0][i] = 0;
        }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};

// 矩阵中的局部最大值

class Solution {
public:
    int getLocal(const vector<vector<int>>& grid, int x, int y) {
        int ans = grid[x][y];
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                ans = max(ans, grid[x + i][y + j]);
            }
        }
        return ans;
    }
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, INT_MIN));
        for (int x = 1; x < n - 1; ++x) {
            for (int y = 1; y < n - 1; ++y) {
                ans[x - 1][y - 1] = getLocal(grid, x, y);
            }
        }
        return ans;
    }
};

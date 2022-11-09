// 最大加号标志

// dp
// 两次遍历找出每个点上下左右最长连续1，以该点为中心能形成的最大加号标志大小为上下左右连续1中最短的那个
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> matrix(n ,vector<int>(n, 1));
        vector<vector<int>> up(n, vector<int>(n));
        vector<vector<int>> down(n, vector<int>(n));
        vector<vector<int>> left(n, vector<int>(n));
        vector<vector<int>> right(n, vector<int>(n));
        for (auto& each : mines) matrix[each[0]][each[1]] = 0;
        // 左上往右下遍历，更新up和left
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != 0) up[i][j] = matrix[i][j] != 0 ? 1 + up[i - 1][j] : 0;
                else up[i][j] = matrix[i][j];

                if (j != 0) left[i][j] = matrix[i][j] != 0 ? 1 + left[i][j - 1] : 0;
                else left[i][j] = matrix[i][j];
            }
        }

        // 右下往左上遍历，更新down和right
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i != n - 1) down[i][j] = matrix[i][j] != 0 ? 1 + down[i + 1][j] : 0;
                else down[i][j] = matrix[i][j];

                if (j != n - 1) right[i][j] = matrix[i][j] != 0 ? 1 + right[i][j + 1] : 0;
                else right[i][j] = matrix[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, min(left[i][j], min(right[i][j], min(up[i][j], down[i][j]))));
            }
        }
        return ans;
    }
};

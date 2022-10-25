// 最短的桥


/*
 *先找到其中一座岛，存储它的所有点的坐标。对另一座岛的所有点，计算其和这些所有坐标距离的最小值
 * */
class Solution {
public:
    int ans = INT_MAX;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& points, bool ok) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || grid[i][j] != 1) return;
        grid[i][j] = 2;
        if (!ok) points.push_back({i, j});
        else {
            for (auto& each : points) ans = min(ans, abs(i - each.first) + abs(j - each.second));
        }
        dfs(grid, i + 1, j, points, ok);
        dfs(grid, i - 1, j, points, ok);
        dfs(grid, i, j - 1, points, ok);
        dfs(grid, i, j + 1, points, ok);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> p1;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, p1, ok);
                    ok = !ok;
                }
            }
        }
        return ans - 1;
    }
};

/*
 *一样先得到第一座岛所有点坐标，然后对每个第一座岛的点以其为起点进行广搜
 *快了不少(O(n^2))，但我果然还是讨厌bfs!!
 * */

class Solution {
private:
    vector<vector<int>> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& points) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || grid[i][j] != 1) return;
        grid[i][j] = 2;
        points.push({i, j});
        dfs(grid, i + 1, j, points);
        dfs(grid, i - 1, j, points);
        dfs(grid, i, j - 1, points);
        dfs(grid, i, j + 1, points);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    int ans = 0;
                    while (!q.empty()) {
                        int q_len = q.size();
                        for (int k = 0; k < q_len; ++k) {
                            auto [x, y] = q.front();
                            q.pop();
                            for (int d = 0; d < 4; ++d) {
                                int nx = x + dir[d][0], ny = y + dir[d][1];
                                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                                    if (grid[nx][ny] == 0) {
                                        q.push({nx, ny});
                                        grid[nx][ny] = 2;
                                    } else if (grid[nx][ny] == 1)return ans;
                                }
                            }
                        }
                        ++ans;
                    }
                }
            }
        }
        return 0;
    }
};

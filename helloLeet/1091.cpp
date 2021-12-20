// shortestPatjBinaryMatrix
//
// BFS
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = 1, n = grid.size();
        if (n == 0 || grid[0][0] == 1) return -1;
        if (n == 1) return 1;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        q.push({0, 0});
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto cur = q.front(); q.pop();
                for (auto d : dir) {
                    int nx = cur.first + d.first, ny = cur.second + d.second;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                        if (nx == n - 1 && ny == n - 1) return ans + 1;
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};

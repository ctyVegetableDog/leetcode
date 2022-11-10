// 获取所有钥匙的最短路径

/*
 *bfs真的恐怖
 * */

class Solution {
private:
    static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    // 状压 + BFS
    // 用三元组x,y,mask表示当前状态，其中x,y为当前位置，mask为当前拥有的钥匙，本题最多6把，可用int来存
    // 先遍历一遍网格，确定开始位置，并且给每个钥匙编号
    // 从起点开始，做4个方向的bfs，如果该位置合法，则根据当前格子属性
    // 若当前是空房间或起点，则考察，是否在和当前mask状态相同时曾到达过该格，若没有则更新状态
    // 若当前是钥匙，则同样先判断是否在mask相同的状态层到达过该格（这里的mask包括该格的钥匙），若没有拿上钥匙后更新状态。之后判断是否拿到了全部钥匙
    // 若当前是锁，则判断有没有对应钥匙，如果有则将其看做空房间考察
    int shortestPathAllKeys(vector<string>& grid) {
        vector<int> key_to_index(26, -1); // 钥匙的编号
        int index = 0, sx = 0, sy = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '@') { // 确定起点
                    sx = i;
                    sy = j;
                } else if (islower(grid[i][j])) { // 给钥匙编号
                    key_to_index[grid[i][j] - 'a'] = index;
                    ++index;
                }
            }
        }

        queue<tuple<int, int , int>> q;
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(1 << index, -1))); // 每有一个钥匙mask就有一位
        dist[sx][sy][0] = 0;
        q.emplace(sx, sy, 0); // 开始一个钥匙没有
        while(!q.empty()) {
            auto [x, y, mask] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) { // 往四个方向bfs
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') { // 位置合法
                    if (grid[nx][ny] == '.' || grid[nx][ny] == '@') { // 空房间或起点
                        if (dist[nx][ny][mask] == -1) { // 此前还未访问过
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    } else if (islower(grid[nx][ny])) { // 钥匙
                        int idx = key_to_index[grid[nx][ny] - 'a'];
                        if (dist[nx][ny][mask | (1 << idx)] == -1) { //没以当前mask访问过
                            dist[nx][ny][mask | (1 << idx)] = dist[x][y][mask] + 1; // 拿上钥匙
                            if ((mask | 1 << idx) == (1 << index) - 1) { // 已经拿到所有钥匙
                                return dist[nx][ny][mask | (1 << idx)];
                            }
                            q.emplace(nx, ny, mask | (1 << idx));
                        }
                    } else { // 锁
                        int idx = key_to_index[grid[nx][ny] - 'A'];
                        if ((mask & (1 << idx)) && dist[nx][ny][mask] == -1) {
                            dist[nx][ny][mask] = dist[x][y][mask] + 1;
                            q.emplace(nx, ny, mask);
                        }
                    }
                }
            }
        }
        return -1;
    }
};

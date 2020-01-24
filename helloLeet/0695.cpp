//Max area of island (bfs)

class Solution {
public:
    stack<pair<int, int> > st;
    int mx = 0;
    void bfs(vector<vector<int> >& grid, int cur) {
        if (st.empty()) {
            mx = max(mx, cur);
            return;
        }
        int i = st.top().first, j = st.top().second;
        st.pop();
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            st.push({i - 1, j}); 
            grid[i - 1][j] = -1;
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == 1) {
            st.push({i + 1, j}); 
            grid[i + 1][j] = -1;
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            st.push({i, j - 1}); 
            grid[i][j - 1] = -1;
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) {
            st.push({i, j + 1}); 
            grid[i][j + 1] = -1;
        }
        bfs(grid, cur + 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = -1;
                    st.push({i, j});
                    bfs(grid, 0);
                }
            }
        }
        return mx;
    }
};

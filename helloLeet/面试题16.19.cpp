// 水域大小
// dfs

class Solution {
public:
    int dfs(vector<vector<bool>>& vis, const vector<vector<int>>& land, int i, int j) {
        if (i >= land.size() || j >= land[0].size() || vis[i][j] || land[i][j] != 0) return 0;
        else {
            vis[i][j] = true;
            return 1 + dfs(vis, land, i - 1, j) + dfs(vis, land, i + 1, j) + dfs(vis, land, i, j - 1) + dfs(vis, land, i, j + 1) + dfs(vis, land, i -1, j - 1) + dfs(vis, land, i - 1,j + 1) + dfs(vis, land, i + 1, j - 1) + dfs(vis, land, i + 1, j + 1);
        }

    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cur = dfs(vis, land, i, j);
                if (cur > 0) ans.push_back(cur);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

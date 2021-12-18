// findCirleNum
class Solution {
public:
    void dfs(const vector<vector<int>>& isConnected, vector<bool>&visited, int n, int i) {
        for (int j = 0; j < n; ++j) {
            if (isConnected[i][j] == 1 && visited[j] == false) {
                visited[j] = true;
                dfs(isConnected, visited, n, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0; // n个城市
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ans;
                dfs(isConnected, visited, n, i);
            }
        }
        return ans;
    }
};

// numWays
// DP
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<int> dp(n);
        dp[0] = 1;
        for (int i = 0; i < k; ++i) {
            vector<int> temp(n);
            for (auto& r : relation) {
                int s = r[0], e = r[1];
                temp[e] += dp[s];
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};

//DFS
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> mp(n);
        for (auto& r : relation) {
            mp[r[0]].push_back(r[1]);
        }
        int ans = 0;
        function<void(int, int)> dfs = [&](int pos, int step) {
            if (step == k) {
                if (pos == n - 1) ans++;
                return;
            }
            for (int e : mp[pos]) {
                dfs(e, step + 1);
            }
        };
        dfs(0, 0);
        return ans;
    }
};

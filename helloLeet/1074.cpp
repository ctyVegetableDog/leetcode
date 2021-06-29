// numSubmatrixSumTarget
// prefix + hashmap
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <=m; ++i) {
            for (int j = 1;j <=n; ++j) {
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        bool chooseM = m > n;
        int ans = 0;
        for (int i = 1; i <= (chooseM ? n : m); ++i) {
            for (int j = i; j <= (chooseM ? n : m); ++j) {
                unordered_map<int, int> mp;
                int cur = 0;
                for (int c = 1; c <= (chooseM ? m : n); ++c) {
                    cur = chooseM ? pre[c][j] - pre[c][i - 1] : pre[j][c] - pre[i - 1][c];
                    if (cur == target) ans++;
                    if (mp.count(cur - target)) ans += mp[cur -target];
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};

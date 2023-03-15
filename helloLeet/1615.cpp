// 最大网络秩

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> cnt(n , 0);
        vector<vector<bool>> hasRoad(n, vector<bool>(n, false));
        for (auto& road : roads) {
            cnt[road[0]]++;
            cnt[road[1]]++;
            hasRoad[road[0]][road[1]] = true;
            hasRoad[road[1]][road[0]] = true;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                ans = max(ans, cnt[i] + cnt[j] - hasRoad[i][j]);
            }
        }
        return ans;
    }
};

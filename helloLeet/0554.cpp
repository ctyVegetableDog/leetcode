// leastBricks (hash map)
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        for (auto& row : wall) {
            int sum = 0, len = row.size();
            for (int i = 0; i < len - 1; ++i) {
                sum += row[i];
                mp[sum]++;
            }
        }
        int mx = 0;
        for (auto& [_, e] : mp) {
            mx = max(mx, e);
        }
        return wall.size() - mx;
    }
};

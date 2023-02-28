// 合并相似的物品

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int> mp(1001, 0);
        for (auto& each : items1) {
            mp[each[0]] += each[1];
        }
        for (auto& each : items2) {
            mp[each[0]] += each[1];
        }
        vector<vector<int>> ans;
        for (int i = 0; i < mp.size(); ++i) {
            if (mp[i] != 0) ans.push_back({i, mp[i]});
        }
        return ans;
    }
};

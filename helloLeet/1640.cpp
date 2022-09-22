// 白给题

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; ++i) mp[arr[i]] = i;
        for (auto& each : pieces) { //每一组
            int idx = mp[each[0]]; //找到组头位置
            for (int i = 0; i < each.size(); ++i) {
                if (each[i] != arr[idx++]) return false;
            }
        }
        return true;
    }
};

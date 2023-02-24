class Solution {
public:
    // 不同数字变为0需要的操作数不同，所以就是统计不同数字的数量
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i : nums) {
            if (mp.count(i) == 0 && i != 0) ++ans;
            mp[i]++;
        }
        return ans;
    }
};

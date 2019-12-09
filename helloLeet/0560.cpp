//use hash map store dp info (really impressive)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0, res = 0;
        mp[0] = 1;
        for (int n : nums) {
            sum += n;
            if (mp.find(sum - k) != mp.end()) res += mp[sum - k];
            if (mp.find(sum) != mp.end()) mp[sum] ++;
            else mp[sum] = 1;
        }
        return res;
    }
};

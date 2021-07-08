// check subarray sum
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        for (int i = 2; i <= n; ++i) {
            mp[pre[i - 2] % k]++;
            if (mp.count(pre[i] % k)) return true;
        }
        return false;
    }
};

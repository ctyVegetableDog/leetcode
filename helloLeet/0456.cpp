// 132 pattern
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> stk;
        int k = INT_MIN, len = nums.size();
        for (int i = len - 1; i >= 0; --i) {
            if (nums[i] < k) return true;
            while (!stk.empty() && stk.back() < nums[i]) {
                k = max(k, stk.back());
                stk.pop_back();
            }
            stk.push_back(nums[i]);
        }
        return false;
    }
};

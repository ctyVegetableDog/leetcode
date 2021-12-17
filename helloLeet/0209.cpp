class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, total = 0, ans = INT_MAX;
        while (right < n) {
            total += nums[right];
            if (total >= target) {
                while (left <= right && total >= target) {
                    total -= nums[left++];
                    ans = min(ans, right - left + 2);
                }
            }
            ++right;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

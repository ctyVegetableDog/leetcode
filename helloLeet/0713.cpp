//two points

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int left = 0, right = 0, prod = 1, n = nums.size(), ans = 0;
        while (right < n) {
            prod *= nums[right];
            while (left <= right && prod >= k) {
                prod /= nums[left++];
            }
            ans += (right - left + 1);
            ++right;
        }
        return ans;
    }
};

// 最大升序子数组和

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int cur_max = 0, ans = 0, len = nums.size();
        for (int i = 0;i < len; ++i) {
            if (i == 0 || nums[i] > nums[i - 1]) cur_max += nums[i];
            else {
                ans = max(ans, cur_max);
                cur_max = nums[i];
            }
        }
        return max(ans, cur_max);
    }
};

//dp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int cur = nums[0];
        int l = nums.size();
        for (int i = 1;i < l; i++) {
            cur += nums[i];
            if (cur < nums[i]) cur = nums[i];
            res = max(res, cur);
        }
        return res;
    }
};

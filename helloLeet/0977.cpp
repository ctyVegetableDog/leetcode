// sorted squares
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 0);
        for (int i = 0, j = len - 1, pos = len - 1; j >= i; --pos) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            } else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
        }
        return ans;
    }
};

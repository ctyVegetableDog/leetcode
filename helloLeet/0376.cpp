//Wiggles Subsequence(dp)

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        unsigned len = nums.size();
        if (len == 0) return 0;
        int up = 1, down = 1;
        for (int i = 1; i < len; ++i) {
            if (nums[i] > nums[i - 1]) down = up + 1;
            else if (nums[i] < nums[i - 1]) up = down + 1;
        }
        return max(up, down);
    }
};

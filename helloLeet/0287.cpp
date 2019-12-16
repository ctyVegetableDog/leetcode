//find the duplicate number (store info in the original array)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i ++) {
            int ix = nums[i] < 0 ? -nums[i] : nums[i];
            if (nums[ix] < 0) return ix;
            else nums[ix] = -nums[ix];
        }
        return -1;
    }
};

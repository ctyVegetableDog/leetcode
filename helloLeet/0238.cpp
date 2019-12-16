//simple logic

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num_of_zero = 0, all = 1, zero_pos = -1;
        vector<int> res(nums.size(),0);
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0) {
                num_of_zero++;
                zero_pos = i;
            }
            else all *= nums[i];
        }
        if (num_of_zero > 1) return res;
        else if (num_of_zero == 1) {
            res[zero_pos] = all;
            return res;
        } else {
            for (int i = 0; i < nums.size(); i ++) res[i] = all/nums[i];
            return res;
        }
    }
};

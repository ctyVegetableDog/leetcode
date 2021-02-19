// Max consist 1
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp = 0, res = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 1) ++temp;
            else {
                res = max(res, temp);
                temp = 0;
            }
        }
        return max(res, temp);
    }
};

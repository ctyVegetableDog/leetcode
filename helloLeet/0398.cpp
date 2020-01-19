//reservoir sampling

class Solution {
private:
    vector<int> nums;

public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int n = 1;
        int res = -1;
        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == target) {
                int r = rand()%n + 1;
                if (r == 1) res = i;
                n++;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

//Increasing Triplet Subsequenece (logic)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int slow = nums[0], fast = INT_MAX, cand = INT_MAX;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > fast) return true;//fast
            else {// < fast
                if (nums[i] <= slow) { // slow
                    if (nums[i] <= cand) {
                        cand = nums[i];
                    } else {
                        slow = cand;
                        fast = nums[i];
                        cand = INT_MAX;
                    }
                } else fast = nums[i];
            }
        }
        return false;
    }
};

//3Sum Cloest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long res = INT_MAX;
        for (int i = 0 ; i < nums.size(); i ++) {
            int tar = target - nums[i], l = i + 1, r = nums.size() - 1;
            long subres = INT_MAX;
            while (l < r) {
                int subsum = nums[l] + nums[r];
                if (abs(subsum - tar) < abs(subres - tar)) subres = subsum;
                if (subsum == tar) return target;
                else if (subsum > tar) r--;
                else l++;
            }
            subres += nums[i];
            if (abs(target - res) > abs(target - subres)) res = subres;
        }
        return res;
    }
};

//3Sums

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            int tar = -nums[i], l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum > tar) r--;
                else if (sum < tar) l++;
                else {
                    vector<int> subres(3, 0);
                    subres[0] = nums[i];
                    subres[1] = nums[l];
                    subres[2] = nums[r];
                    res.push_back(subres);
                    while (l < r && nums[l] == subres[1]) l++;
                    while (l < r && nums[r] == subres[2]) r--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};

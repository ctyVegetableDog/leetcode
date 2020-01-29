//4Sum (same as 3Sum)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        for (int i = 0; i < sz - 1; i ++) {
            for (int j = i + 1; j < sz; j++) {
                int l = j + 1, r = sz - 1, tar = target - nums[i] - nums[j];
                while (l < r) {
                    if (nums[l] + nums[r] > tar) r--;
                    else if (nums[l] + nums[r] < tar) l++;
                    else {
                        vector<int> subres;
                        subres.push_back(nums[i]);
                        subres.push_back(nums[j]);
                        subres.push_back(nums[l]);
                        subres.push_back(nums[r]);
                        res.push_back(subres);
                        while (l < r && nums[l] == subres[2]) l++;
                        while (l < r && nums[r] == subres[3]) r--;
                    }
                }
                while (j + 1 < sz && nums[j + 1] == nums[j]) j++;
            }
            while (i + 1 < sz - 1 && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};

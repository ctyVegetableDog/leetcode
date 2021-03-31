// subset with dup
class Solution {
public:
    vector<vector<int>> res;
    vector<int> subset;
    void updateRes(bool choosePre, int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            res.push_back(subset);
            return;
        }
        updateRes(false, idx + 1, nums);
        if (!choosePre && idx > 0 && nums[idx - 1] == nums[idx]) return;
        subset.push_back(nums[idx]);
        updateRes(true, idx + 1, nums);
        subset.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        updateRes(false, 0, nums);
        return res;
    }
};

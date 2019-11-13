//use set to delete duplicates(if don't wanna use set, check whether nums[i+1]==nums[i] in backtracking)

class Solution {
public:
    vector<vector<int> > res;
    void updateRes(vector<int>& subset, vector<int>& nums, int i,int tar) {
        if (i == tar) {
            res.push_back(subset);
            return;
        }
        vector<int> newset = subset;
        newset.push_back(nums[i]);
        updateRes(newset, nums, i + 1, tar);
        updateRes(subset, nums, i + 1, tar);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        vector<int> subset;
        updateRes(subset, nums, 0, l);
        set<vector<int> > sst(res.begin(), res.end());
        res.assign(sst.begin(), sst.end());
        return res;
    }
};

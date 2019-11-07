//backtracking

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
    vector<vector<int>> subsets(vector<int>& nums) {
        int l = nums.size();
        vector<int> subset;
        updateRes(subset, nums, 0, l);
        return res;
    }
};

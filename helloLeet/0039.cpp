//backtracking(dfs)

class Solution {
public:
    vector<vector<int> > res;
    void dfs(vector<int>& cans, int cur_tar, int st_ix, vector<int>& cur_nums) {
        if (cur_tar == 0) {
            res.push_back(cur_nums);
            return;
        }
        if (cur_tar < 0) return;
        for (int i = st_ix; i < cans.size(); i ++) {
            if (cans[i] > cur_tar) continue;
            cur_nums.push_back(cans[i]);
            dfs(cans, cur_tar-cans[i], i, cur_nums);
            cur_nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return res;
        vector<int> cur_nums;
        dfs(candidates, target, 0, cur_nums);
        return res;
    }
};

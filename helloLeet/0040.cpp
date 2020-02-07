//Combination sum 2 (dfs)

class Solution {
public:
    vector<vector<int> > res;
    void dfs(vector<int>& candidates, int cur_tar, int ix, vector<int>& cur_res) {
        if (cur_tar == 0) {
            res.push_back(cur_res);
            return;
        }
        if (cur_tar < 0) return;
        for (int i = ix; i < candidates.size(); i++) {
            if (i > ix && candidates[i] == candidates[i - 1]) continue;
            cur_res.push_back(candidates[i]);
            dfs(candidates, cur_tar - candidates[i], i + 1, cur_res);
            cur_res.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return res;
        sort(candidates.begin(), candidates.end());
        vector<int> cur_res;
        dfs(candidates, target, 0, cur_res);
        return res;
    }
};

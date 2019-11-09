//STL: next_permutation

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> np = nums;
        do {
            res.push_back(np);
            next_permutation(np.begin(), np.end());
        } while (np != nums);
        return res;
    }
};

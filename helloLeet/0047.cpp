//permutations (STL function next_permutation could work no matter contain duplicates or not)

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> np = nums;
        do {
            res.push_back(np);
            next_permutation(np.begin(), np.end());
        } while (np != nums);
        return res;
    }
};

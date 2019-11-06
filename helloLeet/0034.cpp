//STL:equal_range

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto res = equal_range(nums.begin(), nums.end(), target);
        if (res.first == res.second) return {-1,-1};
        return {res.first - nums.begin(), res.second - nums.begin() - 1};
    }
};

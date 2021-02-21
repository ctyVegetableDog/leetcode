// Longest sub-array with abs limit
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> ms;
        int l = 0, r = 0, res = 0;
        while (r < nums.size()) {
            ms.insert(nums[r]);
            while (*ms.rbegin() - *ms.begin() > limit) {
                ms.erase(ms.find(nums[l++]));
            }
            res = max(res, r - l + 1);
            ++r;
        }
        return res;
    }
};

//STL

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
        /*
            nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), greater<int>());
            return nums[k - 1];
        */
    }
};

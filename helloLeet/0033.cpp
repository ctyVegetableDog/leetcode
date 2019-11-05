//binary search with enumerate (I hate this ques!!!!!!)

class Solution {
public:
    int bsearch(int l, int r, int target, vector<int>& nums) {
        if (l > r) return -1;
        int mid = (l + r)/2;
        if (nums[mid] == target) return mid;
        if ((nums[mid] >= target && target >= nums[l] && nums[l] >= nums[r]) ||
           (nums[r] >= nums[mid] && nums[mid] >= target && target >= nums[l]) ||
           (nums[l] >= nums[r] && nums[r] >= nums[mid] && nums[mid] > target) ||
           (target >= nums[l] && nums[l] >= nums[r] && nums[r] >= nums[mid]))
            return bsearch(l, mid-1, target, nums);
        else return bsearch(mid + 1, r, target, nums);
    }
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = nums.size() - 1;
        return bsearch(0, l, target, nums);
    }
};

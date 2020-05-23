//Peak Index in a Mountain Array (binary search)

class Solution {
public:
    int bs(vector<int>& nums, int l, int r) {
        if (l == r) return l;
        int mid = (l + r) / 2, mid2 = mid + 1;
        if (nums[mid] < nums[mid2]) return bs(nums, mid2, r);
        else return bs(nums, l, mid);
    }
    int peakIndexInMountainArray(vector<int>& A) {
        return bs(A, 0, A.size() - 1);
    }
};

//Find Peak Element (binary search)

/*
	The tricky thing is nums[-1] = nums[n] = -infinity, that's why binary search can work on an unsorted array
	consider 9, 11, 10, 15, 25, 30, 900, 100
	mid is 15 and mid2 is 25, as mid < mid2 and there's an -INF after 100, which means there must be a peak between mid2 and the -INF after 100
	If there's no peak after 25, the number after 25 have to be increasing or decreasing order
	Decreasing:  ..., 15, 25, 24, 23, 22, 21,-INF,  in this case 25 is a peak
	Increasing:  ..., 15, 25, 26, 27, 28, 29,  -INF, in this case the last number is a peak
*/

class Solution {
public:
    
    int bs(vector<int>& nums, int l, int r) {
        if (l == r) return l;
        int mid = (l + r) / 2, mid2 = mid + 1;
        if (nums[mid] < nums[mid2]) return bs(nums, mid2, r);
        else return bs(nums, l, mid);
    }
    
    int findPeakElement(vector<int>& nums) {
        return bs(nums, 0, nums.size() - 1);
    }
};

//Partition equal subset sum (backtracking)

/*
	check if an array could be divided into two subsets, whose sum of elements are equal.
	The question actually is asking to find a subset, whose sum of elements is equial to sum / 2
	So it's a simple dfs ques
	Btw, if sum of initial array is an odd, it'll never find a subset satisfied, so we can just return false.
*/

class Solution {
private:
    bool helper(const vector<int>& nums, int sum, int ix) {
        if (ix >= nums.size()) return false;
        if (sum == nums[ix]) return true;
        if (sum < nums[ix]) return false;
        return helper(nums, sum - nums[ix], ix + 1) || helper(nums, sum, ix + 1);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int n : nums) sum += n;
        if (sum % 2) return false;
        sort(nums.rbegin(), nums.rend());
        sum /= 2;
        return helper(nums, sum, 0);
    }
};

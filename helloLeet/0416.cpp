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

/*
 *使用递推的方法：
 能否分成两个和相等的子集等价于问能否从nums中选任意元素使和恰好等于sum(nums) / 2，变为01背包问题
 * */

class Solution {
public:
    /*
    本题等价于从nums中选取任意件物品，其价值恰好等于c，其中c = sum(nums) / 2;
    */
    bool helper(vector<int>& nums, int c) {
        int n = nums.size();
        vector<bool> dp(c + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = c; j >= 0; --j) {
                if (nums[i - 1] <= j) dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp[c];
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1) return false;
        total /= 2;
        return helper(nums, total);
    }
};

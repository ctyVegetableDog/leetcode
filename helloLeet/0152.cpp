//very classic dp
/*
	use two array to store the max product and min prodcut(as negetive multiply a negetive well be positive)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = nums.size(), res = nums[0];
        int dp_max[l + 1], dp_min[l + 1];
        dp_max[0] = 1;
        dp_min[0] = 1;
        for (int i = 1; i <= l; i++) {
            dp_max[i] = max(nums[i - 1], nums[i - 1] * dp_max[i - 1]);
            dp_max[i] = max(dp_max[i], nums[i - 1] * dp_min[i - 1]);
            dp_min[i] = min(nums[i - 1], nums[i - 1] * dp_max[i - 1]);
            dp_min[i] = min(dp_min[i], nums[i - 1] * dp_min[i - 1]);
            res = max(res, dp_max[i]);
        }
        return res;
    }
};

/*
	but in this case, dp[i] only based on dp[i-1], so we don't have to use an array to store the state
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l = nums.size(), res = nums[0], dp_max = 1, dp_min = 1;
        for (int i = 1; i <= l; i++) {
		//when nums[i-1] is negetive, max will be min
            if (nums[i - 1] < 0) swap(dp_max, dp_min);
            dp_max = max(nums[i - 1], nums[i - 1] * dp_max);
            dp_min = min(nums[i - 1], nums[i - 1] * dp_min);
            res = max(res, dp_max);
        }
        return res;
    }
};

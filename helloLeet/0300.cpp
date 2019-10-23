//DP without Binary search O(n^2)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        int l = nums.size();
        if (l == 0) return 0;
        int dp[l];
        for (int i = 0;i < l; i++) dp[i] = 1;
        for (int i = 1; i < l; i++) {
            int cur_max = 0;
           for (int j = i -1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    cur_max = max(cur_max, dp[j]);
                }
            }
            dp[i] = cur_max + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};

//DP with BS
/*
	create a vector to store the current seq
	for eachnum in nums
	if eachnum > seq.end() seq.pushpack(eachnum)
	else find the position (with BS) in seq which eachnum could be inserted in, such as seq:[1,3,4], eachnum = 2 after after fun, seq will become 
	seq:[1,2,4]
	for the res, just return the len of seq
	(I'll use other's solution)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.size() <= 1) return nums.size();
        
        vector<int> vec;
        vec.push_back(nums[0]);
        
        for(int i=1; i < nums.size(); i++)
        {
            int n = vec.back();
            
            if(n < nums[i])
                vec.push_back(nums[i]);
            else
            {
                auto iter = lower_bound(vec.begin(), vec.end(), nums[i]);
                *iter = nums[i];
            }
        }
        
        return vec.size();
    }
};

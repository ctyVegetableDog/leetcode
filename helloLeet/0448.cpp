//find missing number from 1-size(arr) in an int array arr
/*
	1. Take arr = {4,3,2,7,8,2,3,1} as example
	2. The normal solution with O(n) space is use an array isIn = {1,1,1,1,0,0,1,1} to save info.
	3. isIn[i] = (i + 1) in arr
	4. It's totally same as {-,-,-,-,+,+,-,-} as all of the number is postive(1-size(arr));
	5. So we can just change the number in the original arr to the negative one to save the info.
	6. For example, the first number in arr is 4, so we have to change arr[3] to negative.(base on 3.)
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i ++) {
            int m = abs(nums[i]) - 1;//get the index
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }
        for (int i = 0; i < nums.size(); i ++) if (nums[i] > 0) res.push_back(i + 1);
        return res;
    }
};

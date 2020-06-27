//Non-decreasing Array(greedy)

/*
when nums[i] < nums[i - 1] happens, only two choice could be choose:
1.make nums[i] bigger
2.make nums[i - 1] smaller

And obviously make some value bigger will lead to more risk, so make nums[i - 1] smaller is always the better choice. But when nums[i] less than nums[i - 2] as well, the only thing we can do is make nums[i] bigger as we can not reduce nums[i - 1] and nums[i - 2] at the same time.
*/

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size() && cnt <= 1; ++i) {
            if (nums[i] < nums[i - 1]) {
                ++cnt;
                if (i - 2 < 0 || nums[i] >= nums[i - 2]) nums[i - 1] = nums[i];
                else nums[i] = nums[i - 1];
            }
        }
        return cnt <= 1;
    }
};

//Permutation	two pointer	one swap

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size();
        int ok = false;
        for (int i = l - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                for (int j = i ;j < l; j ++) {
                    if(nums[j] <= nums[i - 1]) {
                        int t = nums[i - 1];
                        nums[i - 1] = nums[j - 1];
                        nums[j - 1] = t;
                        ok = true;
                        break;
                    }
                }
                if (!ok) {
                    int t = nums[i - 1];
                    nums[i - 1] = nums[l-1];
                    nums[l-1] = t;
                }
                for (int m = i, n = l - 1;m < n; m++, n--) {
                    int t = nums[m];
                    nums[m] = nums[n];
                    nums[n] = t;
                }
                return;
            }
        }
        reverse(nums.begin(), nums.end());
        return;
    }
};

//nothing

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, cur = 0, last = nums.size() - 1;
        while(l <= last){
            if (nums[l] == 0){
                int temp = nums[l];
                nums[l] = nums[cur];
                nums[cur] = temp;
                cur++;
                l++;
            } else if (nums[l] == 1) l++;
            else if (nums[l] == 2) {
                int temp = nums[l];
                nums[l] = nums[last];
                nums[last] = temp;
                last--;
            }
        }
    }
};

// 检查数组是否经排序和轮转得到

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int mi = nums[0];
        bool ok = false;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                if (ok) return false;
                else ok = true;
            }
            if (ok && nums[i] > mi) return false;
        }
        return true;
    }
};

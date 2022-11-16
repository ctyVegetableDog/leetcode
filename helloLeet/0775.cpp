// 全局倒置与局部倒置

class Solution {
public:
    // 一个局部倒置：nums[i] > nums[i + 1]
    // 一个全局倒置：nums[i] > (i+1)位之后的任意一个数
    // 一个局部倒置一定是一个全局倒置，所以改为找出全局倒置中的非局部倒置，非局部倒置是nums[i] > nums[k] k > i + 1
    // 所以可以维护一个mi，表示(i + 2~n - 1)之中的最小值
    // 当nums[i] > mi表示发生了一个非局部倒置，直接false
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int mi = nums[n - 1];
        for (int i = n - 3; i >= 0; --i) {
            if (nums[i] > mi) return false;
            mi = min(mi, nums[i + 1]);
        }
        return true;
    }
};

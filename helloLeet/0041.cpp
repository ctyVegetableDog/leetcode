// 缺失的第一个正数

/*
 *难点是要想到答案肯定在[1,N + 1]之间（N = size）而和数组中数字实际的取值范围无关，假设不在[1,N]那么1～N可以占满所有的数组位置，答案只能是N + 1
 * 原地哈希
 其实之前做过类似的，好像是数组中重复的数字
 这类问题的条件是数组中的重要元素都是正数且不大于数组的下标，这样就可以用下标来存储额外的信息
 比如当访问第i号数字时，可以把nums[nums[i]]设为负的表示nums[i]已被访问
 * */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) if (nums[i] <= 0) nums[i] = len + 1; // 全变成不影响的正数
        for (int i = 0; i < len; ++i) {
            if (abs(nums[i]) <= len && nums[abs(nums[i]) - 1] > 0) nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1]; //每遍历到一个数就把它对应位置的数变为负数（变相哈西）
        }
        for (int i = 0; i < len; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return len + 1;
    }
};

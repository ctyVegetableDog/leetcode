// 分割数组

/*
 *接雨水同款，找每个元素左侧最值和右侧最值
 * */

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int len = nums.size();
        vector<int> l_max(len, -1), r_min(len, INT_MAX);
        for (int i = 1; i < len; ++i) l_max[i] = max(nums[i - 1], l_max[i - 1]);
        for (int i = len - 2; i >= 0; --i) r_min[i] = min(nums[i + 1], r_min[i + 1]);
        for (int i = 1; i < len - 1; ++i) {
            if (l_max[i] <= r_min[i]) return nums[i] < r_min[i] ? i + 1 : i;
        }
        return 1;
    }
};

/*
 *一次遍历的办法，假设当前在pos位置划分，此时认为有pos左侧元素最大值mx小于pos右侧元素，若在向pos右侧遍历的时候找到某个元素小于了mx，即说明mx之前的元素都应该属于left数组
 * */
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int len = nums.size();
        int mx = nums[0], ans = 0, cur_max = nums[0];
        for (int i = 1; i < len - 1; ++i) {
            cur_max = max(cur_max, nums[i]);
            if (nums[i] < mx) {
                mx = cur_max;
                ans = i;
            }
        }
        return ans + 1;
    }
};

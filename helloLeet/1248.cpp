// 统计【优美子数组】


// 滑动窗口
class Solution {
public:
    // 先统计每个奇数的位置
    // 滑动窗口找到k个奇数
    // 该窗口中奇数可以构成的子数组由【窗口左边界和其上一个奇数的位置】和【窗口右边界和其下一个奇数位置】决定
    int numberOfSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> odds;
        odds.push_back(-1);
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 1) odds.push_back(i); // 保存每个奇数的下标
        }
        odds.push_back(len);
        if (k > odds.size() - 2) return 0;

        int ans = 0, left = 1, right = k;
        while (right < odds.size() - 1) {
            ans += (odds[left] - odds[left - 1]) * (odds[right + 1] - odds[right]);
            ++right;
            ++left;
        }
        return ans;
    }
};

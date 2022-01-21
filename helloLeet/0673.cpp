// number of LIS (good ques)
//
// 方法1:DP O(n^2)
// 可以定义两个数组
// cnt[i]:到i为止最长LIS个数
// dp[i]:到i为止最长LIS长度
// 对每一个i，都检查其之前对每一个为止j，若nums[i] > nums[j]则说明i可以接在j后面形成LIS，此时：
// 若dp[j] + 1 < dp[i]:则说明当前的j和i组成的LIS长度，不如之前的j和i组成的，直接跳过
// 若dp[j] + 1 > dp[i]:则说明当前的j和i可以组成更长的LIS，此时需要直接更新cnt[i]为cnt[j]
// 若dp[j] + 1 == dp[i]:则当前j和i可以组成和目前最长LIS一样长的不同LIS，所以cnt会累加 cnt[i] += cnt[j]

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 0, ans = 0;
        if (n == 1) return 1;
        vector<int> cnt(n), dp(n); // i为止最长LIS个数 --- i为止最长LIS长度
        for (int i = 0; i < n; ++i) {
            cnt[i] = 1;
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) { // i可以跟在j后面形成新序列
                    if (dp[j] + 1 > dp[i]) { // 当前的j可以和nums[i]组成更长的
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[j] + 1 == dp[i]) { // 存在多个长度一样的不同的j，每个累加
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (dp[i] > maxLen) {
                ans = cnt[i];
                maxLen = dp[i];
            } else if (dp[i] == maxLen) ans += cnt[i];
        }
        return ans;
    }
};

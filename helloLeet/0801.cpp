// 使序列递增的最小交换次数

/*
 *状态机DP
 状态为 考虑是否交换当前位置
 dp[i][0]为不交换当前位置，dp[i][1]为交换，显然每次交换都将使交换次数 + 1
 所以有：
 若nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1] 那么可以不交换，此时dp[i][0] = dp[i - 1][0], dp[i][1] = dp[i - 1][1] + 1（如果第i - 1个交换了，那么第i个要交换回来）
 同理nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1] 那么可以交换，此时dp[i][0] = dp[i - 1][1]（上轮交换过了） dp[i][1] = dp[i - 1][0] + 1（上轮没交换）
 如果两个都满足，取较小的那个就行

 因为转移之和i-1有关，可以使用滚动数组来优化
 * */

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size();
        int unswapped = 0, swapped = 1; // unswapped不交换第一位swapped直接交换第一位
        for (int i = 1; i < len; ++i) {
            int cur_un = len, cur_sw = len; // 方便之后去min
             if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) { // 可以不交换
                 cur_un = unswapped;
                 cur_sw= swapped + 1; // 上一位如果交换了，这一位只能交换回来
             }
             if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) { // 可以交换
                cur_un = min(cur_un, swapped); // 上一位交换了
                cur_sw = min(cur_sw, unswapped + 1);
             }
             unswapped = cur_un;
             swapped = cur_sw;
        }
        return min(swapped, unswapped);
    }
};

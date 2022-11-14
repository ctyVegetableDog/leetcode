// 数组的均值分割

class Solution {
public:
    // nums中有n个元素
    // 假设A中有k个元素，B中有n - k个元素，此时有 sum(A) / k = (sum(B)) / (n - k)
    // 移项得 sum(A) * (n - k) = sum(B) * k
    // sum(A) * n = (sum(A) + sum(B)) * k
    // sum(A) * n = sum(nums) * k
    // sum(A) = sums(nums) / n * k
    // 问题转化为，能否从sums中取出k个元素，使它们的和恰好为k * avg，其中avg为sums(nums) / n即nums的平均数

    // 状态转移比一般01背包复杂，用bool dp[i][x]表示，选择i个元素刚好可以构成x，显然有dp[0][0] = true
    // 假设现在扫描到了第j个元素，那么在考虑第j个元素之前，可能选择的元素个数为0~j-1个，即i from 0 to j - 1
    // 假如dp[i][x] = true，那么有dp[i + 1][x + nums[j]] = true，表示选择第j个元素，可以构成x + nums[j]
    // 用三层循环

    // 优化
    // 根据sum(A) = sums(nums) / n * k，sum(A)必然是整数，所以若是找不到k满足 sum(nums) * k % n == 0那么必然不存在答案。另外，因为A和B的对称性，可以将A抽象成实际A,B中较短的那条，此时k最大为n / 2（若A中元素个数多于n / 2，即k > n / 2，那B就满足元素数少于 n / 2此时可以将B看为A）。
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size(), k = n / 2, sums = accumulate(nums.begin(), nums.end(), 0);
        bool ok = false;
        for (int i = 1; i <= k; ++i) {
            if (sums * i % n == 0) {
                ok = true;
                break;
            }
        }
        if (!ok) return false;

        vector<unordered_set<int>> dp(k + 1); // dp[i]选择i个元素时可以达到的值的set
        dp[0].insert(0); //dp[i][x] = 0;
        for (int j = 0; j < n; ++j) { // 遍历每一个元素
            for (int i = k; i >= 1; --i) { // 选择该元素的所有可能
                for (int each : dp[i - 1]) {
                    int sub_sum = each + nums[j]; // j被选择后数组A的和
                    if (sub_sum * n == sums * i) return true;
                    dp[i].insert(sub_sum); // 加入
                }
            }
        }
        return false;
    }
};

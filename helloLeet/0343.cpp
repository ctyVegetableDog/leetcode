// integer break
// 整数拆分
// 方法1:DP

class Solution {
public:
    int integerBreak(int n) {
        // dp[i]表示将i拆成两个或以上的数字时，最大的乘积，0和1都不可再拆，显然有dp[0] = dp[1] = 0
        vector<int> dp(n + 1, 0);
        // 对于大于1的每一个数都拆分
        for (int i = 2; i <= n; ++i) {
            int currentMax = 0;
            // 对于大于1的每一个数都拆分为j和i-j两个数，其中i-j可以继续拆，也可以不拆，继续拆的话，能拆成的最大乘积为dp[i-j]，不拆的话就是j * (i - j)
            for (int j = 1; j < i; ++j) {
                currentMax = max(currentMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = currentMax;
        }
        return dp[n];
    }
};

// 方法2:数学
// 对于任何数i，都可以做一次最小拆分，显然拆成i - 1和1没有意。
// 对于i - 2和2，2 * (i - 2) >= i在i >= 4时总是成立，所以，对于任何>=4的数，将其拆分总是更好的选择，也就是说，假设最后的结果是
// ans = a1 * a2 * a3 *...* ak; 其中有a1 + a2 + ... + ak = n，任意ai(i >=0 && i <= k)都满足 ai >= 1 && ai <= 3
// 并且ai = 1没意义
// 也就是说ai不是2就是3
// 对于2和3的最小公倍数6，显然拆成2 * 2 * 2 = 8不如3 * 3 = 9
// 所以只需要将n拆分为尽量多的3即可
// 需要注意的是当i <= 4时，不再需要拆分

class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) return n - 1;
        int quptient = n / 3, remainder = n % 3;
        if (remainder == 0) return pow(3, quptient);
        else if (remainder == 1) return pow(3, quptient - 1) * 4;
        else return pow(3, quptient) * 2;
    }
};

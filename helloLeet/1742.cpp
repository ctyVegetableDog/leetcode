// 盒子中小球的最大数量

class Solution {
public:
    int helper(int n) {
        int ans = 0;
        while (n != 0) {
            ans += n % 10;
            n /= 10;
        }
        return ans;
    }
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int cur = helper(i);
            mp[cur]++;
            ans = max(ans, mp[cur]);
        }
        return ans;
    }
};

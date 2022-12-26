// 统计同构字符串的数目

class Solution {
public:
    int countHomogenous(string s) {
        long long cnt = 0, ans = 0;
        int n = s.size();
        long long mod = 1e9 + 7;
        char cur = 'A';
        for (int i = 0; i < n; ++i) {
            if (cur != s[i]) {
                cur = s[i];
                cnt = 1;
            } else {
                ++cnt;
            }
            ans += (cnt % mod);
            ans %= mod;
        }
        return (int)ans;
    }
};

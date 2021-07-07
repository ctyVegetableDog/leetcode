// countPairs
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int max_num = (1 << 22), mod = 1e9 + 7, ans = 0;
        unordered_map<int, int> mp;
        for (auto& e : deliciousness) {
            for (int i = 1; i <= max_num; i <<= 1) {
                int tar = i - e;
                if (mp.count(tar) != 0) {
                    ans += mp[tar];
                    if (ans >= mod) ans -= mod;
                }
            }
            mp[e]++;
        }
        return ans;
    }
};

// total hamming distance
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sz = nums.size(), res = 0;
        vector<int> cnt(32, 0);
        for (int num : nums) {
            int i = 0;
            while (num > 0) {
                cnt[i] += (num & 1);
                num >>= 1;
                ++i;
            }
        }

        for (int e : cnt) {
            res += e * (sz - e);
        }
        return res;
    }
};

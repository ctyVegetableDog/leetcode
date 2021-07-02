// maxIceCream
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        vector<int> freq(100001);
        for (int i : costs) freq[i]++;
        for (int i = 1; i <= 100000; ++i) {
            if (coins >= i) {
                int buy = min(freq[i], coins / i);
                coins -= i * buy;
                ans += buy;
            } else break;
        }
        return ans;
    }
};

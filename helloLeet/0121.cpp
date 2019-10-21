//nothing

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, mi = INT_MAX;
        int l = prices.size();
        for (int i = 0; i < l; i++) {
            res = max(res, prices[i] - mi);
            mi = min(mi, prices[i]);
        }
        return max(res, 0);
    }
};

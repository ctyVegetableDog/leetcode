// Matryoshka doll envelops problem (LIS)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int len = envelopes.size();
        if (len <= 1) return len;
        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        vector<int> vec = {envelopes[0][1]};
        for (int i = 1; i < len; ++i) {
            if (envelopes[i][1] > vec.back()) vec.push_back(envelopes[i][1]);
            else {
                auto iter = lower_bound(vec.begin(), vec.end(), envelopes[i][1]);
                *iter = envelopes[i][1];
            }
        }
        return vec.size();
    }
};

// max product
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size(), ans = 0;
        vector<int> bit_mask;
        for (string &s : words) {
            int num = 0;
            for (char c : s) {
                num |= (1 << (c - 'a'));
            }
            bit_mask.push_back(num);
        }
        for (int i = 1; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if ((bit_mask[i] & bit_mask[j]) == 0) {
                    int temp = words[i].size() * words[j].size();
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};

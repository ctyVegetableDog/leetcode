// irritable shop owner (sliding window)
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int mx_ones_value = 0, zero_value = 0, tm_ones_value = 0;
        for (int l = 0, r = 0; r < grumpy.size(); ++r)
        {
            if (X-- > 0) {
                if (grumpy[r] == 0) zero_value += customers[r];
                else tm_ones_value += customers[r];
            } else {
                tm_ones_value += grumpy[r] * customers[r];
                tm_ones_value -= grumpy[l] * customers[l];
                zero_value += (!grumpy[r]) * customers[r];
                ++l;
            }
            mx_ones_value = max(mx_ones_value, tm_ones_value);
        }
        return zero_value + mx_ones_value;
    }
};

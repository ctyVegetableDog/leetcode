//bit oper and INT_MIN and INT_MAX

class Solution {
public:
    int divide(int dividend, int divisor) {
        int res = 0;
        if (divisor == INT_MIN) return dividend == INT_MIN ? 1:0;
        if (dividend == INT_MIN) {
            if (divisor == 1) return INT_MIN;
            dividend -= (divisor > 0) ? -divisor : divisor;
            res += 1;
        }
        int a = (dividend > 0) ? dividend : -dividend;
        int b = (divisor > 0) ? divisor : -divisor;
        for (int i = 31; i >= 0; i --) {
            if ((a >> i) >= b) {
                if (res + (1 << i) >= INT_MAX) return INT_MAX;
                res += (1 << i);
                a -= (b << i);
            }
        }
        if ((dividend^divisor) < 0) return -res;
        else return res;
    }
};

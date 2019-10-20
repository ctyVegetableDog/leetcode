//INT_MAX and INT_MIN (2^32 - 1, -2^32 - 1)

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int last = x % 10;
            if ((res > INT_MAX/10 || (res == INT_MAX/10 && last > 7)) || (res < INT_MIN/10 || (res == INT_MIN/10 && last < -8))) return 0;
            res *= 10;
            res += last;
            x /= 10;
        }
        return res;
    }
};

// integer replacement
class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) return 32;
        int ans = 0;
        while (n != 1) {
            if (n % 2 == 0) n >>= 1;
            else {
                if (n != 3 && ((n >> 1) & 1) == 1) n++;
                else n--;
            }
            ans++;
        }
        return ans;
    }
};

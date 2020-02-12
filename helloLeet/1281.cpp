//Subtract the Product and Sum of Digits of an Integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        int m = 1, s = 0;
        while (n) {
            int k = n % 10;
            m *= k;
            s += k;
            n /= 10;
        }
        return m - s;
    }
};

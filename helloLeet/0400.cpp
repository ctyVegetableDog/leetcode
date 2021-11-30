// find Nth Digit
class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;
        while (len * 9 * pow(10, len - 1) < n) {
            n -= len* 9 * pow(10, len - 1);
            len++;
        }

        long number_len_min = (long)pow(10, len - 1);
        long number = number_len_min + n / len - 1;
        n -= (number - number_len_min + 1) * len;
        if (n == 0) return (int)number % 10;
        else return (int) (number + 1) / (int) pow(10, len - n) % 10;
    }
};

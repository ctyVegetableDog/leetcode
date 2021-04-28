// judge Square Sum
// BST
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = (int)sqrt(c);
        while (left <= right) {
            long temp = left * left + right * right;
            if (temp == c) return true;
            else if (temp > c) --right;
            else ++left;
        }
        return false;
    }
};

// 二进制数字转字符串

class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        while (ans.size() <= 33 && num != 0) {
            num *= 2;
            if (num >= 1) {
                ans.push_back('1');
                num -= 1;
            } else {
                ans.push_back('0');
            }
        }
        return ans.size() <= 32 ? ans : "ERROR";
    }
};

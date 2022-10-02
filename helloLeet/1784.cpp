// 检查二进制字符串字段

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool in = false, off = false;
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (!in && s[i] == '1') in = true;
            else if (in && s[i] == '0') off = true; 
            else if (off && s[i] == '1') return false;
        }
        return true;
    }
};

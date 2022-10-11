// 仅执行一次字符串交换能否使两个字符串相等

/*
 *白给题
 * */

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        pair<char, char> p{'1', '1'};
        int len = s1.size();
        int ok = false;
        for (int i = 0; i < len; ++i) {
            if (s1[i] != s2[i]) {
                if (p.first == '1') {
                    p.first = s1[i];
                    p.second = s2[i];
                } else {
                    if (ok) return false;
                    else {
                        if (s1[i] != p.second || s2[i] != p.first) return false;
                        ok = true;
                    }
                }
            }
        }
        if (p.first != '1' && !ok) return false;
        return true;
    }
};

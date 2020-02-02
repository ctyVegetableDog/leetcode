//Count and say (just brute force)

class Solution {
public:
    string getNext(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11";
        string s = getNext(n - 1), res = "";
        int len = s.size(), cnt = 1;
        for (int i = 1; i < len; i ++) {
            if (s[i] == s[i - 1]) cnt++;
            else {
                res.push_back('0' + cnt);
                res.push_back(s[i - 1]);
                cnt = 1;
            }
            if (i == len - 1) {
                res.push_back('0' + cnt);
                res.push_back(s[i]);
            }
        }
        return res;
    }
    string countAndSay(int n) {
        return getNext(n);
    }
};

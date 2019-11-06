//string

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length(), lb = b.length();
        int i = la - 1, j = lb - 1;
        int bs = 0;
        string res = "";
        while (i >= 0 || j >= 0) {
            int dq = 0;
            if (i >= 0) dq += a[i] - '0';
            if (j >= 0) dq += b[j] - '0';
            dq += bs;
            char dd = dq%2 + '0';
            res = dd + res;
            bs = dq/2;
            i--;
            j--;
        }
        if (bs > 0) res = '1' + res;
        return res;
    }
};

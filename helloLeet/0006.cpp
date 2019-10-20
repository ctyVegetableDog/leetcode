//numRows substrings

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string slist[numRows];
        int ix = 0;
        bool ok = true;
        string res = "";
        for (char c : s) {
            slist[ix] += c;
            if (ok) ix ++;
            else ix --;
            if (ix == 0 || ix == numRows -1) ok = !ok;
        }
        for (string subs : slist) res += subs;
        return res;
    }
};

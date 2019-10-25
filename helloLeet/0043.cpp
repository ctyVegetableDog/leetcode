//string <-> int

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        string res = "";
        int ix = 0, l1 = num1.length(), l2 = num2.length();
        int reslen = l1 + l2 -1;
        vector<int> ires;
        for (int i = 0; i < reslen; i ++) ires.push_back(0);
        for (int i = 0; i < l2; i++) {
            ix = i;
            for (int j = 0; j < l1; j++) {
                ires[ix] += (num2[i] - '0') * (num1[j] - '0');
                ix++;
            }
        }
        for (int i = reslen - 1; i > 0; i--) {
            res += ires[i]%10 + '0';
            ires[i - 1] += ires[i]/10;
        }
        res += ires[0]%10 + '0';
        if(ires[0]/10 > 0) res += (ires[0]/10) + '0';
        reverse(res.begin(), res.end());
        return res;
    }
};

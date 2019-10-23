//INT_MAX and INT_MIN

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while (str[i] == ' ') i++;
        if (str[i] != '+' && str[i] != '-' && (str[i] > '9' || str[i] < '0')) return 0;
        int res = 0;
        bool ok = false;
        if (str[i] == '+') i++;
        else if (str[i] == '-') {
            ok = true;
            i++;
        }
        int l = str.length();
        for (i; i < l; i++) {
            if (!(str[i] >= '0' && str[i] <= '9')) break;
            if (!ok && (res > INT_MAX/10 || (res == INT_MAX/10 && (str[i] > '7')))) return INT_MAX;
            if (ok && (res > -INT_MIN/10 || (res == -INT_MIN/10 && (str[i] >= '8')))) return INT_MIN;
            res *= 10;
            res += str[i] - '0';
        }
        if (ok) res = -res;
        return res;
    }
};

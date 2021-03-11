// Calculator
class Solution {
public:
    int calculate(string s) {
        vector<int> v;
        int cur_num = 0, len = s.size();
        char oper = '+';
        for (int i = 0; i < len; ++i) {
            if (isdigit(s[i])) {
                cur_num = cur_num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == len - 1) {
                switch(oper) {
                    case '+':
                        v.push_back(cur_num);
                        break;
                    case '-':
                        v.push_back(-cur_num);
                        break;
                    case '*':
                        v.back() *= cur_num;
                        break;
                    case '/':
                        v.back() /= cur_num;
                        break;
                }
                cur_num = 0;
                oper = s[i];
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};

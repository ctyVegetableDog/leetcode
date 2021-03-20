// Reverse-polish
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> vec;
        for (string& s : tokens) {
            if (isNumber(s)) {
                vec.push_back(atoi(s.c_str()));
            } else {
                int num_r = vec.back();
                vec.pop_back();
                int num_l = vec.back();
                vec.pop_back();
                switch (s[0]) {
                    case '+':
                        vec.push_back(num_l + num_r);
                        break;
                    case '-':
                        vec.push_back(num_l - num_r);
                        break;
                    case '*':
                        vec.push_back(num_l * num_r);
                        break;
                    case '/':
                        vec.push_back(num_l / num_r);
                        break;
                }
            }
        }
        return vec[0];
    }

    bool isNumber(const string& s) {
        return !(s == "+") && !(s == "-") && !(s == "*") && !(s == "/");
    }
};

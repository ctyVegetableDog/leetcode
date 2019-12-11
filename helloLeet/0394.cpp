//stack store previous status

class Solution {
public:
    string decodeString(string s) {
        string cur_str = "";
        int num = 0;
        stack<int> num_st;
        stack<string> str_st;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num *= 10;
                num = num + (s[i] - '0');
            } else if (s[i] == '[') {
                num_st.push(num);
                num = 0;
                str_st.push(cur_str);
                cur_str = "";
            } else if (s[i] == ']') {
                int n = num_st.top();
                num_st.pop();
                string st = str_st.top();
                str_st.pop();
                string temp = cur_str;
                for (int j = 0; j < n - 1; j ++) temp += cur_str;
                cur_str = st + temp;
            } else cur_str += s[i];
        }
        return cur_str;
    }
};

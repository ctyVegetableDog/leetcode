// 设计Goal解析器

class Solution {
public:
    string interpret(string command) {
        string ans;
        int len = command.size();
        for (int i = 0; i < len; ++i) {
            if (command[i] == 'G') ans.push_back('G');
            else if (command[i] == '(') {
                if (command[i + 1] == ')') ans.push_back('o');
                else {
                    ans.push_back('a');
                    ans.push_back('l');
                    ++i;
                    ++i;
                }
                ++i;
            }
        }
        return ans;
    }
};

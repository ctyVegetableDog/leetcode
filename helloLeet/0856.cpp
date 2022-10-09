// 括号的分数

class Solution {
public:

    int scoreOfParentheses(string s) {
        int weight = 0, ans = 0, len = s.size();
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                weight = weight == 0 ? 1 : weight * 2;
            } else {
                if (s[i - 1] != ')')
                    ans += weight;
                weight = weight == 1 ? 0 : weight / 2;
            }
        }
        return ans;
    }
};

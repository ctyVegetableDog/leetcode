// 使括号有效的最少添加

class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, ans = 0; // cnt当前存储的左括号数，ans每当cnt == 0来了一个右括号，立马补充一个左括号加到ans里
        for (char c : s) {
            if (cnt > 0 && c == ')') --cnt; // 
            else if (cnt == 0 && c == ')') ++ans;
            else if (c == '(') ++cnt;
        }
        return cnt + ans;
    }
};

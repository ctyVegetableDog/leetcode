// 解析布尔表达式

class Solution {
    /*
    其实和用栈实现计算器没什么区别，重点是要想到运算符后必然是左括号
    对逗号外的其他所有字符，都入栈
    如果是右括号，则开始计算子表达式的值，不断弹出直到遇到左括号，弹出过程中记录f和t的个数然后再弹出一下将运算符弹出，根据运算符和f,t的个数计算子表达式的结果并入栈
    若op为!，则后只有一个字符（f/t或已经被计算过了的子表达式结果），此时f=1的说明是t
    op为&，则f=0才是t，否则f
    op为| t > 0就是t
    */
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for (char c : expression) {
            if (c == ')') {
                int f = 0, t = 0;
                while (st.top() != '(') { // 计算f/t个数
                    if (st.top() == 'f') ++f;
                    else ++t;
                    st.pop();
                }
                st.pop();
                char op = st.top(); st.pop();
                if (op == '!') st.push(f == 1 ? 't' : 'f');
                else if (op == '&') st.push(f == 0 ? 't' : 'f');
                else st.push(t > 0 ? 't' : 'f');
            } else if (c == ',') continue;
            else st.push(c);
        }
        return st.top() == 't';
    }
};

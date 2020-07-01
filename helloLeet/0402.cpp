//Remove K Digits (stack and greedy)

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.size()) return "0";
        
        stack<char> st;
        for (char c : num) {
            while (k > 0 && !st.empty() && st.top() > c) {
                st.pop();
                --k;
            }
            st.push(c);
        }
        
        while (k > 0) {
            st.pop();
            --k;
        }
        string res;
        
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        while (res. back() == '0' && res.size() > 1) res.pop_back();
        reverse(res.begin(), res.end());
        return res.empty() ? "0" : res;
    }
};

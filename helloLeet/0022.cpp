//recurion (kinda dp and it's a good ques)

class Solution {
public:
    vector<string> res;
    void addStrings(string s,int n, int m, int tar) {
        if (s.length() == 2 * tar) res.push_back(s);
        if (n < tar) addStrings(s + '(' , n + 1, m,tar);
        if (m < n) addStrings(s + ')', n, m + 1, tar);
    }
    vector<string> generateParenthesis(int n) {
        addStrings("", 0, 0, n);
        return res;
    }
};

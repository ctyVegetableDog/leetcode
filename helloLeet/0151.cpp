//Reverse Words in a String

class Solution {
public:
    string reverseWords(string s) {
        string res;
        for (int l = s.size() - 1; l >= 0; --l) {
            if (s[l] != ' ') {
                int r = l;
                while (l >= 0 && s[l] != ' ') --l;
                res += s.substr(l + 1, r - l) + " ";
            }
        }
        if (res.back() == ' ') res.pop_back();
        return res;
    }
};

//backtracking

class Solution {
public:
    vector<string> res;
    void addString(string s, int i, string digits) {
        if (s.length() == digits.length()) {
            res.push_back(s);
            return;
        }
        if (digits[i] == '2') {
            addString(s + 'a', i + 1, digits);
            addString(s + 'b', i + 1, digits);
            addString(s + 'c', i + 1, digits);
        } else if (digits[i] == '3'){
            addString(s + 'd', i + 1, digits);
            addString(s + 'e', i + 1, digits);
            addString(s + 'f', i + 1, digits);
        } else if (digits[i] == '4') {
            addString(s + 'g', i + 1, digits);
            addString(s + 'h', i + 1, digits);
            addString(s + 'i', i + 1, digits);
        } else if (digits[i] == '5') {
            addString(s + 'j', i + 1, digits);
            addString(s + 'k', i + 1, digits);
            addString(s + 'l', i + 1, digits);
        } else if (digits[i] == '6') {
            addString(s + 'm', i + 1, digits);
            addString(s + 'n', i + 1, digits);
            addString(s + 'o', i + 1, digits);
        } else if (digits[i] == '7') {
            addString(s + 'p', i + 1, digits);
            addString(s + 'q', i + 1, digits);
            addString(s + 'r', i + 1, digits);
            addString(s + 's', i + 1, digits);
        } else if (digits[i] == '8') {
            addString(s + 't', i + 1, digits);
            addString(s + 'u', i + 1, digits);
            addString(s + 'v', i + 1, digits);
        } else if (digits[i] == '9') {
            addString(s + 'w', i + 1, digits);
            addString(s + 'x', i + 1, digits);
            addString(s + 'y', i + 1, digits);
            addString(s + 'z', i + 1, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") return res;
        addString("", 0, digits);
        return res;
    }
};

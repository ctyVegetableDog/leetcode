// Split palindrome
class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        for (int l = 0, r = s.size() - 1; l <= r; ) {
            if (s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }

    void helper(vector<vector<string>>& res, vector<string> this_turn, string s) {
        if (!s.size()) {
            res.push_back(this_turn);
            return;
        }
        for (int i = 1; i <= s.size(); ++i) {
            string pre_string = s.substr(0, i);
            if (isPalindrome(pre_string)) {
                this_turn.push_back(pre_string);
                helper(res, this_turn, s.substr(i));
                this_turn.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        helper(res, {}, s);
        return res;
    }
};

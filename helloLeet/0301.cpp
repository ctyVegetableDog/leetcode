//Remove invalid parentheses

/*
	dfs
	0.count the number of '(' and ')' which needed to removed
	1.traverse the string, for each '(' and ')' remove it or not
	2.use a unordered_set to remvove duplicates
	
	there's a opti
	consider ((())
	the res that we move the 1st, 2nd or 3rd '(' will be same, instead of use an unordered_set, we can just move the first one
	the solution is quit difficult to understand, but anyway we'll back
*/

class Solution {
private:
    vector<string> res;
    void dfs(const string& s, int ix, int left, int right, int pair, string path) {
        if (ix == s.size()) {
            if (left == 0 && right == 0 && pair == 0) res.push_back(path);
            return;
        }
        if (left < 0 || right < 0 || pair < 0) return;
        char c = s[ix];
        if (c == '(') {
            if (ix == 0 || s[ix - 1] != c)
                for (int i = 0; ix + i < s.size() && s[ix + i] == c && i < left; i++)
                    dfs(s, ix + i + 1, left - i - 1, right, pair, path);
            dfs(s, ix + 1, left, right, pair + 1, path + c);
        } else if (c == ')') {
            if (ix == 0 || s[ix - 1] != c)
                for (int i = 0; ix + i < s.size() && s[ix + i] == c && i < right; i++)
                    dfs(s, ix + i + 1, left, right - i -1, pair, path);
            dfs(s, ix + 1, left, right, pair - 1, path + c);
        } else {
            dfs(s, ix + 1, left, right, pair, path + c);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') left++;
            if (c == ')') {
                if (left > 0) left--;
            }
        }
        dfs(s, 0, left, right, 0, "");
        return res;
    }
};

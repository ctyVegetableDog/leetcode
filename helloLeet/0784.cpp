//backtracking

class Solution {
public:
    vector<string> res;
    void getRes(string S, int l, string cur) {
        if (l == S.size()) {
            res.push_back(cur);
            return;
        }
        if (S[l] >='a' && S[l] <= 'z') {
            getRes(S, l + 1, cur + S[l]);
            char c = S[l] - 32;
            getRes(S, l + 1, cur + c);
        } else if (S[l] >= 'A' && S[l] <= 'Z') {
            getRes(S, l + 1, cur + S[l]);
            char c = S[l] + 32;
            getRes(S, l + 1, cur + c);
        }else getRes(S, l + 1, cur + S[l]);
    }
    vector<string> letterCasePermutation(string S) {
        getRes(S, 0, "");
        return res;
    }
};

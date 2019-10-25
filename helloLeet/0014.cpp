//common prefix

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if (strs.empty()) return res;
        int l = strs.size();
        for (int i = 0; i < strs[0].length(); i++){
            for (int j = 0; j < l; j ++) {
                if (i > strs[j].length() || strs[j][i] != strs[0][i]) return res;
            }
            res += strs[0][i];
        }
        return res;
    }
};

// custom sort string
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> cnt(26, 0);
        string res;
        for (char t : T) {
            ++cnt[t - 'a'];
        }
        for (char s : S) {
            for (int i = 0; i < cnt[s - 'a']; ++i) {
                res += s;
            }
            cnt[s - 'a'] = 0;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            for (int i = 0; i < cnt[c - 'a']; ++i) {
                res += c;
            }
        }
        return res;
    }
};

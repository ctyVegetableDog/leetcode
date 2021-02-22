// Longest repeated char after change
class Solution {
public:
    int characterReplacement(string s, int k) {
        int mp[26] = {0};
        int mxlen = 0;
        int l = 0, r = 0;
        for(; r < s.size(); ++r) {
            ++mp[s[r] - 'A'];
            mxlen = max(mxlen, mp[s[r] - 'A']);
            if (r - l + 1 > mxlen + k) {
                --mp[s[l] - 'A'];
                ++l;
            }
        }
        return s.size() - l;
    }
};

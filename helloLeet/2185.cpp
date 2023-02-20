// 统计包含给定前缀的字符串

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0, len = pref.size(), i = 0;
        for (auto& w : words) {
            if (w.size() < len) continue;
            for (i = 0; i < len; ++i) {
                if (w[i] != pref[i]) break;
            }
            if (i == len) ++cnt;
        }
        return cnt;
    }
};

// 统计一致字符串数目

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> mp(26, false);
        for (char c : allowed) mp[c - 'a'] = true;
        int ans = 0;
        for (auto& word : words) {
            bool ok = true;
            for (char c : word) {
                if (!mp[c - 'a']) {
                    ok = false;
                    break;
                }
            }
            if (ok) ++ans;
        }
        return ans;
    }
};

//hash map

class Solution {
public:
    char findTheDifference(string s, string t) {
        int mp[26];
        memset(mp, 0 ,sizeof(mp));
        for (int i = 0; i < s.size(); i ++) mp[s[i] - 'a']++;
        for (int i = 0; i < t.size(); i ++) mp[t[i] - 'a']--;
        for (int i = 0; i < 26; i++) if (mp[i] == -1) return char('a' + i);
        return 'a';
    }
};

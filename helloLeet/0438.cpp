//Find All Anagrams in a String

/*
	Typical slide window
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sc(26, 0), pc(26, 0), res;
        if (s.size() < p.size()) return res;
        for (int i = 0; i < p.size(); i++) {
            sc[s[i] - 'a']++;
            pc[p[i] - 'a']++;
        }
        if (sc == pc) res.push_back(0);
        for (int i = 1; i <= s.size() - p.size(); i++) {
            sc[s[i - 1] - 'a']--;
            sc[s[i + p.size() - 1] - 'a']++;
            if (sc == pc) res.push_back(i);
        }
        return res;
    }
};

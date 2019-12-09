//hash map

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (char c : magazine) {
            if(mp.find(c) == mp.end()) mp[c] = 1;
            else mp[c] ++;
        }
        for (char c : ransomNote) {
            if(mp.find(c) == mp.end()) return false;
            mp[c]--;
            if (mp[c] < 0) return false;
        }
        return true;
    }
};

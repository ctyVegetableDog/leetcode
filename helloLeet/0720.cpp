//Longest Word in Dictionary (hash)

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_map<string, int> mp;
        string res;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].length() == 1 || mp.count(words[i].substr(0, words[i].size() - 1)))            {
                res = words[i].size() > res.size() ? words[i] : res;
                ++mp[words[i]];
            }
        }
        return res;
    }
};

//hash map

class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char , int> mp;
        for (char c : s) mp[c]++;
        vector<string> v(s.size() + 1, "");
        for (auto& it:mp) v[it.second].append(it.second,it.first);
        for (int i = s.size(); i > 0; i--) if (!v[i].empty()) res += v[i];
        return res;
    }
};

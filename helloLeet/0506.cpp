// find relative ranks
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int, int> mp;
        vector<string> ans;
        vector<int> help(score.begin(), score.end());
        sort(score.begin(), score.end(), greater<int>());
        int i = 1;
        for (int each : score) {
            mp[each] = i++;
        }
        for (int i = 0; i < help.size(); ++i) {
            if (mp[help[i]] == 1) ans.push_back("Gold Medal");
            else if (mp[help[i]] == 2) ans.push_back("Silver Medal");
            else if (mp[help[i]] == 3) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(mp[help[i]]));
        }
        return ans;
    }
};

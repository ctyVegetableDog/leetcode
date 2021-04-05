// numRabbits (Greedy)

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int res = 0;
        unordered_map<int, int> mp;
        for (int a : answers) ++mp[a];
        for (auto& iter : mp) {
            res += (iter.second % (iter.first + 1)) ? (iter.second / (iter.first + 1) + 1) * (iter.first + 1) : iter.second;
        }
        return res;
    }
};

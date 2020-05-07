//hash (has better solution)

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        int mx;
        bool ok = false;
        for (int i : arr) ++mp[i];
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            if (iter->first == iter->second) {
                if (!ok) {
                    mx = iter->first;
                    ok = true;
                } else mx = (mx > iter->first) ? mx : iter->first;
            }
        }
        return ok ? mx : -1;
    }
};

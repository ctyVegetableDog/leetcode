//X of a Kind in a Deck of Cards (gcd)

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> cnt;
        int res = 0;
        for (int n : deck) ++cnt[n];
        for (auto &i : cnt) res = __gcd(i.second, res);
        return res > 1;
    }
};

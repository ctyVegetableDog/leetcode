//Pairs of Songs With Total Durations Divisible by 60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        vector<int> mp(60);
        for (int i : time) {
            res += mp[(60 - i % 60) % 60];
            ++mp[i % 60];
        }
        return res;
    }
};

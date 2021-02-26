// Puzzle
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mp;
        for (string& s:words){
            int mask = 0;
            for (char ch : s) {
                mask |= 1 << (ch - 'a');
            }
            if (__builtin_popcount(mask) <= 7) {
                ++mp[mask];
            }
        }

        vector<int> ans;
        for (string& pz:puzzles) {
            int mask = 0, cnt = 0;
            for (int i = 1 ; i < 7; ++i) {
                mask |= 1 << (pz[i] - 'a');
            }
            int submask = mask;
            do{
                int s = submask | 1 << (pz[0] - 'a');
                if (mp.count(s)) cnt += mp[s];
                submask = (submask - 1) & mask;
            }while (submask != mask);
            ans.push_back(cnt);
        }
        return ans;
    }
};

// original digits
class Solution {
public:
    string originalDigits(string s) {
        vector<int> mp(26, 0);
        vector<int> cnt(10, 0);
        for (char c : s) {
            mp[c - 'a']++;
        }
        cnt[0] = mp['z' - 'a'];
        cnt[6] = mp['x' - 'a'];
        cnt[2] = mp['w' - 'a'];
        cnt[8] = mp['g' - 'a'];
        cnt[4] = mp['u' - 'a'];
        cnt[3] = mp['h' - 'a'] - cnt[8];
        cnt[5] = mp['f' - 'a'] - cnt[4];
        cnt[7] = mp['v' - 'a'] - cnt[5];
        cnt[1] = mp['o' - 'a'] - cnt[4] - cnt[0] - cnt[2];
        cnt[9] = mp['i' - 'a'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i <= 9; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans.push_back(i + '0');
            }
        }
        return ans;
    }
};

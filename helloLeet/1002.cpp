//hash map

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        int mp[26];
        memset(mp, 0, sizeof(mp));
        for (int i = 0; i < A[0].size(); i ++) mp[A[0][i] - 'a']++;
        for (int i = 1; i < A.size(); i ++) {
            int cur_mp[26];
            memset(cur_mp, 0, sizeof(cur_mp));
            for (int j = 0; j < A[i].size(); j ++) cur_mp[A[i][j] - 'a']++;
            for (int j = 0; j < 26; j ++) mp[j] = min(mp[j], cur_mp[j]);
        }
        for (int i = 0; i < 26; i ++) {
            for (int j = 0; j < mp[i]; j ++) {
                string s = "";
                char c = 'a' + i;
                s += c;
                res.push_back(s);
            }
        }
        return res;
    }
};

//统计子串中唯一字符

/*
 *所有子串，每个子串中只出现过一次的字符的个数。实际上是对于原字符串s中的每一个字符c，c可以在多少个子串中是唯一字符即为c对总数的贡献。对于c，其向左直到遇到另一个c为止，不断添加字符都可以构成不含邮重复c的子串，向右同理，所以对于c，记录下每个c出现的位置c[0],c[1],c[2]...
 对于c[1]（第2个c），包含它的不含有重复c的子串有(c[1] - c[0]) * (c[2] - c[1])个，即左侧可以一直添加字符直到遇到另一个c，共有c[1] - c[0] - 1个，另外还可以一个字符都不添加再加一种情况，即c[1] - c[0]哥，右侧同理
 * */
class Solution {
public:
    int uniqueLetterString(string s) {
        int len = s.size(), ans = 0;
        vector<vector<int>> cnt(26, vector<int>(0));
        for (int i = 0; i < len; ++i) cnt[s[i] - 'A'].push_back(i);
        for (int i = 0; i < 26; ++i) {
            if (!cnt[i].empty()) {
                cnt[i].insert(cnt[i].begin(), -1);
                cnt[i].push_back(len);
                for (int j = 1 ; j < cnt[i].size() - 1; ++j) ans += (cnt[i][j] - cnt[i][j - 1]) * (cnt[i][j + 1] - cnt[i][j]);
            }
        }
        return ans;
    }
};

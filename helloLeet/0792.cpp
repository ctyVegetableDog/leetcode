// 匹配子序列的单词数

class Solution {
public:
    /*
    暴力匹配每一个word会超时
    预先将每一种字符在s中的位置储存下来
    每一个word都考察其每一个字符
    若其存在比上一个字符更往后的位置，则匹配成功
    因为位置数组都是有序的，可以二分
    */
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> mp(26); //mp[i]为(i + 'a')字符在s中的位置，多个位置生序排列
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            mp[s[i] - 'a'].push_back(i); // mp中所有的数组直接就都生序排列
        }
        int ans = 0;
        for (auto& w : words) {
            int last_pos = -1;
            bool ok = true;
            for (int i = 0; i < w.size(); ++i) {
                auto iter = upper_bound(mp[w[i] - 'a'].begin(), mp[w[i] - 'a'].end(), last_pos);
                if (iter == mp[w[i] - 'a'].end()) {
                    ok = false;
                    break;
                }
                last_pos = *iter;
            }
            ans += ok;
        }
        return ans;
    }
};

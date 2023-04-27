// 最长字符串链

class Solution {
private:
    unordered_map<string, int> w_cnt;
public:
    int dfs(const string &word) {
        int cnt = w_cnt[word];
        if (cnt != 0) return cnt; // 之前已经被计算过了
        for (int i = 0; i < word.size(); ++i) { //依次删除词中的每一个字母
            string temp = word.substr(0, i) + word.substr(i + 1);
            if (w_cnt.count(temp)) { // 得到的前身在words中
                cnt = max(cnt, dfs(temp)); // 计算以前身作为结尾的词链的长度
            }
        }
        return w_cnt[word]=  cnt + 1;
    }
    int longestStrChain(vector<string>& words) {
        for (auto& w : words) w_cnt[w] = 0;
        int ans = 0;
        for (auto& w : words) ans = max(ans, dfs(w));
        return ans;
    }
};

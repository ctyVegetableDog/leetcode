// 旋转数字

/*
 *数位dp
 * */

class Solution {
private:
    vector<int> cand = {2, 5, 6, 9, 0, 1, 8};
public:
    int dfs(vector<vector<int>>& dp, const vector<int>& number, int cur_pos, bool flag, bool zoe) {
        if (cur_pos < 0) return zoe ? 0 : 1; //需要不全是0/1/8 (zero/one/eight)hhh
        if (!flag && dp[cur_pos][zoe] != -1) return dp[cur_pos][zoe];
        int u_bound = flag ? number[cur_pos] : 9; // 如果迄今为止都是贴着放，那么上限是number[cur_pos]否则0～9都能选
        int res = 0;
        for (int i = 0; i < 7; ++i) { //从候选中选
            if (cand[i] <= u_bound) { //小于上界
                if (i >= 0 && i <= 3) { //选的是2/5/6/9
                    res += dfs(dp, number, cur_pos - 1, flag && (cand[i] == number[cur_pos]), false);
                } else { // 选的是0/1/8
                    res += dfs(dp, number, cur_pos - 1, flag && (cand[i] == number[cur_pos]), zoe);
                }
            }
        }
        if (!flag) dp[cur_pos][zoe] = res;
        return res;
    }
    int rotatedDigits(int n) {
        vector<int> number;
        while (n > 0) {
            number.push_back(n % 10);
            n /= 10;
        }
        int len = number.size();
        vector<vector<int>> dp(len, vector<int>(2, -1));
        return dfs(dp, number, len - 1, true, true);
    }
};

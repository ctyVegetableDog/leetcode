// 水果成篮

/*
 *刺鼻题让老子调了半小时，真是老了
 * */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> last(n + 1); // 每种水果上一次出现的位置
        int b1 = fruits[0], b2 =-1; // 记录当前的两种水果
        int cur = 0, ans = 0, i = 0;
        while (i < n && fruits[i] == b1) {
            ++cur;
            last[b1] = i;
            ++i;
        }
        if (i == n) return cur;
        b2 = fruits[i];
        last[b2] = i;
        ++cur;
        ++i;
        ans = max(cur, ans);
        while(i < n) {
            if (fruits[i] != b1 && fruits[i] != b2) {
                int lastest = min(last[b1], last[b2]) == last[b1] ? b1 : b2;
                cur = i - last[lastest];
                if (lastest == b1) b1 = fruits[i];
                else b2 = fruits[i];
            } else ++cur;
            last[fruits[i]] = i;
            ans = max(ans, cur);
            ++i;
        }
        return ans;
    }
};

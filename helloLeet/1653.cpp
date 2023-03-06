// 使字符串平衡的最少删除次数

class Solution {
public:
    int minimumDeletions(string s) {
        int b_left = 0, a_right = 0;
        for (char c : s) {
            if (c == 'a') a_right++;
        }
        int  ans = b_left + a_right;
        for (char c : s) {
            if (c == 'a') a_right--; 
            else b_left++;
            ans = min(b_left + a_right, ans);
        }
        return ans;
    }
};

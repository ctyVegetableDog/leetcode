// 神奇的字符串

/*
 *前3个数是1，2，2。指针i指向第3个数2，从这里开始往里头加数字。
 初始状态因为已经两个2，所以开始加1，cur_num = 1
 每次往里加str[i]个cur_num，然后翻转cur_num就行
 * */

class Solution {
public:
    int magicalString(int n) {
        vector<int> str;
        str.push_back(1);
        str.push_back(2);
        str.push_back(2);
        int cur_num = 1;
        int i = 2, ans = 1;
        while (str.size() < n) {
            for (int j = 0; j < str[i]; ++j) {
                str.push_back(cur_num);
                if (cur_num == 1) ++ans;
                if (str.size() >= n) return ans;
            }
            ++i;
            cur_num = cur_num == 1 ? 2 : 1;
        }
        return ans;
    }
};

// 字符串轮转

/*
 *判断一个字符串是否由另一个旋转而成
 一般这种题都可以将原字符串复制一份接在后面，这样就变为字符串匹配问题了
 * */

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 != len2) return false;
        // 构建next数组，思路是模式串自己和自己匹配，另外定义只有一个字符的串，没有前后缀
         vector<int> next(len2, -1); 
         int i = -1, j = 0;
         while (j < len2 - 1) { // 减1的是因为先加再赋值
             if (i == -1 || s2[i] == s2[j]) { // 字符匹配成功
                ++i;
                ++j;
                next[j] = i;
             } else { // 匹配不成功
                i = next[i]; // 回溯前缀
             }
         }
         s1 = s1 + s1;
         i = 0, j = 0;
         // next[0] = -1是精髓，当主串和模式串不匹配时模式串回滚（往后移动），如果当第一位都不匹配时，则需要再后移一位，用主串的下一位匹配模式串第一个字符，此时有模式串指针j = 0，主串指针i = i，不匹配j = next[j] = next[0] = -1，下一次迭代j == -1，此时直接i++; j++; 模式串回到第一位，主串后移一位
         while (i < 2 * len1 && j < len2) {
             if (j == -1 || s1[i] == s2[j]) {
                 ++i;
                 ++j;
             } else j = next[j];
         }
         return j == len2;
    }
};

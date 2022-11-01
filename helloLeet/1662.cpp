// 检查两个字符串数组是否相等

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, ii = 0, j = 0, jj = 0, len1 = word1.size(), len2 = word2.size();
        while (i < len1 && j < len2) {
            if (word1[i][ii++] != word2[j][jj++]) return false;
            if (ii >= word1[i].size()) {
                ++i;
                ii = 0;
            }
            if (jj >= word2[j].size()) {
                ++j;
                jj = 0;
            }
        }
        return !(i < len1 - 1 || j < len2 - 1 || (i == len1 - 1 && ii < word1[i].size()) || (j == len2 - 1 && jj < word2[j].size()));
    }
};

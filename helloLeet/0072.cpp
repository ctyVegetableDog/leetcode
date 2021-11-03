//minmum oper to transform a string to another(very good dp ques)

class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            dp[i][j] = dp[i - 1][j - 1]->w1[i] == w2[j]
            dp[i][j] = dp[i - 1][j - 1] + 1->change
            dp[i][j] = dp[i][j - 1] + 1->insert consider this special condition that w1 == "", then if we wann transform w1 to w2, the only choice is insert characters into w1, in this process, there is no i - 1 in w1 as i is always 0
            dp[i][j] = dp[i - 1][j]->delete, same as insert with w2 is empty, so we only can delete characters from w1
        */
        int l1 = word1.length(), l2 = word2.length();
        int dp[l1 + 1][l2 + 1];
        for (int j = 0; j <= l2; j ++) dp[0][j] = j;
        for (int i = 0; i <= l1; i ++) dp[i][0] = i;
        for (int i = 1; i <= l1; i ++) {
            for (int j = 1;j <=l2; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]) + 1;
                }
            }
        }
        return dp[l1][l2];
    }
};

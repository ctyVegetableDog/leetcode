/*
choose each number i from 1 to n as the root, and then, there could be i-1 numbers for the left subtree and n-i numbers for the right as for each binary search tree(BST), every i for left < root < every j from right.
Therefore, there could be G(n) = G(0)G(n-1)+G(1)G(n-2)+...+G(n-1)G(0).
Based on that, dp is reasonable.
Time is O(n^2)
*/

class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = 0;
        for (int i = 2; i <= n; i ++)
            for (int j = 1; j <= i; j ++)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};

/*
Beyond dp, the sequence of G(n) is called Catelan number
C0 = 1, Cn+1 = 2(2n+1)Cn/n+2
*/

class Solution {
public:
    int numTrees(int n) {
        long C = 1;
        for (int i = 0; i < n; ++i)
            C = C * 2 * (2 * i + 1) / (i + 2); 
        return  (int)C;
    }
};

//find the least nubmer of perfect square numbers which sum to n

/*
	a number b must be equal to m + i * i
*/

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp = {0};
        while (dp.size() <= n) {
            int m = dp.size(), res = INT_MAX;
            for (int i = 1; i * i <= m; i ++) res = min(res, dp[m - i*i] + 1);
            dp.push_back(res);
        }
        return dp[n];
    }
};

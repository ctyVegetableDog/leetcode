//Counting Bits

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) return {0};
        vector<int> dp(num + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        int k = 2;
        while (k <= num) {
            for (int i = k; i < 2 * k; i ++) {
                if (i == num + 1) return dp;
                if (i < (3 * k)/2) dp[i] = dp[i - k/2];
                else dp[i] = dp[i - k] + 1;
            }
            k *= 2;
        }
        return dp;
    }
};

/*
	Another solution is more technical
	i & (i - 1) drops the lowest bit of 1, for instance:
	2 & (2 - 1) = 10 & 01 = 00, the lowest 1 bit(the first bit) been droped
	3 & (3 - 1) = 11 & 10 = 10, the lowest 1 bit(the last bit) been droped
	this method while drop exactly one bit, so we have to plus that bit (+1)
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};

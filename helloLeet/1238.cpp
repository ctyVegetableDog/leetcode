// 循环码排列

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans; // 从0生成格雷码
        ans.push_back(0);
        int pre = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = ans.size() - 1; j >=0; --j) {
                ans.push_back(pre + ans[j]);
            }
            pre <<= 1;
        }
        // 顺序的格雷码从0开始，相邻的数只有一位不同。所以可以将顺序格雷码全部异或上start，只有一位不同的两个数异或上同一个数，依然只有一位不同。
        for (int i = 0; i < ans.size(); ++i) ans[i] ^= start;
        return ans;
    }
};

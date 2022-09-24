// 前缀和

/*
 *朴实无华的好题
 * */

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int len = code.size();
        vector<int> ans(len);
        if (k == 0) return ans;
        vector<int> pre(2 * len + 1); // 这种循环前缀和一般都是开两倍长度的前缀和数组，做两倍长度的前缀和
        for (int i = 1; i <= 2 * len; ++i) {
            pre[i] += pre[i - 1] + code[(i - 1) % len];
        }
        if (k > 0) { // 如果是i之后的k个数的和，直接是pre[i + k] - pre[i]，因为做了两倍长度的前缀和，所以不怕循环问题
            for (int i = 1; i <= len; ++i) ans[i - 1] = pre[i + k] - pre[i];
        } else { // 如果是i之前的k个数的和，那么先往后移动len位，然后去其之前的k位就行，因为k是负数，直接pre[i + len - 1] - pre[i + len + k - 1]
            for (int i = 1; i <= len; ++i) ans[i - 1] = pre[i + len -1] - pre[i + len + k - 1];
        }
        return ans;
    }
};

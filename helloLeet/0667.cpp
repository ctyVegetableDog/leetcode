// 脑经急转弯题


class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans;
        int st = 1, ed = n, remain = n - k;
        for (int i = 0; i < k; ++i) { // 先放前k个
            if (i % 2 == 0) {
                ans.push_back(st++);
            } else {
                ans.push_back(ed--);
            }
        }
        if (k % 2 == 0) {//再放剩下的，如果k是偶数，则剩下的降序排列，否则升序
            while (remain--) ans.push_back(ed--);
        } else {
            while(remain--) ans.push_back(st++);
        }
        return ans;
    }
};

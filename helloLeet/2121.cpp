// 相同元素的间隔之和

class Solution {
public:
    /*
    arr[i]对应的间隔之和为其和其之前的所有相同元素的间隔之和，和其之后的所有元素的间隔之和的和，即
    ans[i] = prefix[i] + suffix[i]
    而以prefix举例，prefix[i]等于prefix[i - 1] + 第i号之前的与arr[i]相等元素的个数 * (i - 上一个和arr[i]相等元素的下标) （画图的话很明确）
    后缀同理
    */
    vector<long long> getDistances(vector<int>& arr) {
        int len = arr.size();
        unordered_map<int, int> cnt; // 扫描到arr[i]时，其之前出现过的值为arr[i]的元素的个数
        unordered_map<int, int> last; // 上一个和arr[i]相等的元素的下标
        vector<long long> pre(len, 0); // 前缀和
        vector<long long> ans(len, 0);
        for (int i = 0; i < len; ++i) {
            pre[i] = cnt[arr[i]] * (i - last[arr[i]]) + pre[last[arr[i]]];
            ans[i] += pre[i]; // ans[i]等于其前缀和加后缀和，这里先算前缀和
            cnt[arr[i]]++;
            last[arr[i]] = i;
        }
        
        cnt.clear(); // 清空，来计算后缀和
        last.clear();
        pre.clear();
        pre.assign(len, 0);

        for (int i = len - 1; i >= 0; --i) {
            pre[i] = cnt[arr[i]] * (last[arr[i]] - i) + pre[last[arr[i]]];
            ans[i] += pre[i];
            cnt[arr[i]]++;
            last[arr[i]] = i;
        }
        return ans;
    }
};

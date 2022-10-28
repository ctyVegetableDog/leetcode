// 子数组的最小值的和

class Solution {
public:
    // 找每个元素左右第一个比其小的元素
    // 两次单调栈 找左侧第一个比它大的，从左往右遍历，单调递增栈
    int sumSubarrayMins(vector<int>& arr) {
        long long mod = 1e9 + 7;
        int len = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> l_v(len); // 左侧第一个比其大的元素
        for (int i = 0; i < len; ++i) {
            while (st.top() != -1 && arr[st.top()] >  arr[i]) st.pop();
            l_v[i] = st.top(); // 弹到-1说明没有比它大的
            st.push(i);
        }

        vector<int> r_v(len);
        while(!st.empty()) st.pop(); // 清空栈，改为从右往左的单调递增栈
        st.push(len);

        for (int i = len - 1; i >= 0; --i) {
            while(st.top() != len && arr[st.top()] >= arr[i]) st.pop(); // 这里处理相等的情况，不然和从左往右找会有重复
            r_v[i] = st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < len; ++i) {
            long long cur = (arr[i] % mod * (i - l_v[i] + mod) % mod * (r_v[i] - i + mod) % mod) % mod;
            ans += ((arr[i] % mod * (i - l_v[i] + mod) % mod * (r_v[i] - i + mod) % mod) % mod);
            ans %= mod; // 模你妈香油哦怕是
        }
        return ans;
    }
};

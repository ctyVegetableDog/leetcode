// 子数组范围和

/*
 *单调栈
 * */

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int len = nums.size();
        stack<int> st;
        vector<int> l_large(len); // 左侧第一个比nums[i]大的元素下标
        vector<int> l_small(len); // ...小
        vector<int> r_large(len); //右侧...大
        vector<int> r_small(len); //右侧...小

        // 从左往右扫描单调递减栈，更新l_large
        st.push(-1); //哨兵， nums[0]至少在一个区间充当l_max，就是[nums[0], nums[0]]，所以0 - nums[0]至少得为1
        for (int i = 0; i < len; ++i) {
            while (st.top() != -1 && nums[st.top()] <= nums[i]) st.pop();
            l_large[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        // 左往右单调递增，更新l_small
        st.push(-1);
        for (int i = 0; i < len; ++i) {
            while (st.top() != -1 && nums[st.top()] >= nums[i]) st.pop();
            l_small[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        // 右往左单调递减，更新r_large
        st.push(len); // 哨兵，同理nums[len - 1]至少在[nums[len - 1], nums[len - 1]]充当r_max
        for (int i = len -1; i >= 0; --i) {
            while (st.top() != len && nums[st.top()] < nums[i]) st.pop(); // 不取等号避免重， 比如[3,3,3,3]，如果都取等号，第二个三的 l_large为-1, (i - l_large) = 2, r_large为4, (r_large - i) = 3，即它将在包含它的所有区间内担任左右边界，然而第三个3同理，所以在[3,[3,3],3]内（还有其他的区间内），第2个和第3个三都担任边界，导致重复。如果右侧不取等号，那么r_large为[1,2,3,4]，此时(r_large - i)都是1，即[3,[3,3],3]中[3,3]唯一右边界就是第3个3
            r_large[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        // 右往左单调递增，更新r_small
        st.push(len);
        for (int i = len -1; i >= 0; --i) {
            while (st.top() != len && nums[st.top()] > nums[i]) st.pop();
            r_small[i] = st.top();
            st.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < len; ++i) {
            ans += static_cast<long long>((r_large[i] - i)) * nums[i] * (i - l_large[i]); // 充当的max
            ans -= static_cast<long long>((r_small[i] - i)) * nums[i] * (i - l_small[i]); // 充当的min
        }
        return ans;
    }
};

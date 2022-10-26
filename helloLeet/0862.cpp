// 和至少为K的最短子数组

class Solution {
public:
    /*
    假设最终答案的子数组是[a,b]，对于nums中每一个元素，其作为a时，与之对应的b是其右侧第一个前缀和比它至少大k的元素
    考虑使用一个队列存储，当扫描到下标i时，假设队列开头是qf，此时比较prefix[i]和prefix[qf]，如果满足prefix[i] - prefix[qf] >= k，则i就是当qf作为a时的b，因为i之后的元素和qf组合出的子数组长度只会更大
    另一方面，当扫描到i时，队列中所有比i大的元素都不可能作为最终答案的a，因为i之后prefix比它们至少大k的元素，都将比prefix[i]至少大k，即和i可以组合成更短的子数组，所以可以直接将所有prefix比prefix[i]大的元素弹出。这样就使每次入队的元素都比队中所有元素大，即队列具有单调递增的性质。这样就可以使用双端队列，每次处理完头部后，不断弹出满足条件的尾部即可
    */
    int shortestSubarray(vector<int>& nums, int k) {
        int len = nums.size();
        vector<long> prefix(len + 1);
        for (int i = 0; i < len; ++i) prefix[i + 1] = prefix[i] + nums[i];
        deque<int> dq;
        int ans = len + 1;
        for (int i = 0; i <= len; ++i) { // 从0开始，处理prefix[1]之间大于等于k的情况
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) dq.pop_back(); // 前缀和比当前元素还大的不可能作为答案的区间起点
            dq.push_back(i);
        }
        return ans == len + 1 ? -1 : ans;
    }
};

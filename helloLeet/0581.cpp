//there's a solution with constant space, but can't understand

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < nums.size(); i ++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = nums.size() - 1; i >= 0; i --) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }
        return r > l ?  r - l + 1 : 0;
    }
};

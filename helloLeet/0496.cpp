//Next greater element1 (stack and hash map)

/*
	Use a stack to find the next number greater/smaller than each node in an array
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        vector<int> res;
        int mx = INT_MIN;
        for (int i = 0; i < nums2.size(); i++) {
            if (st.empty() || st.top() >= nums2[i]) st.push(nums2[i]);
            else {
                while (!st.empty() && st.top() < nums2[i]) {
                    mp[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (mp.find(nums1[i]) == mp.end()) res.push_back(-1);
            else res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};

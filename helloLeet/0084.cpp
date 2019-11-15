//dp[left] and dp[right] (good ques)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int sz = heights.size();
        vector<int> left(sz, -1);
        vector<int> right(sz, -1);
        left[0] = -1;
        right[sz - 1] = sz;
        for (int i = 1; i < sz; i++) {
            int l = i - 1;
            while(l >= 0 && heights[l] >= heights[i])
                l = left[l];
            left[i] = l;
            
        }
        for (int i = sz - 2; i >= 0; i --) {
            int r = i + 1;
            while (r < sz && heights[r] >= heights[i])
                r = right[r];
            right[i] = r;
        }
        int mx = 0;
        for (int i = 0; i < sz; i ++)
            mx = max(mx, heights[i] * (right[i] - left[i] - 1));
        return mx;
    }
};

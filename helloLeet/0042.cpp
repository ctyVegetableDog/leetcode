// trap
// DP
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), res = 0;
        if(len == 0) return 0;
        vector<int> leftmax(len), rightmax(len);
        leftmax[0] = height[0];
        for (int i = 1; i < len; ++i) leftmax[i] = max(leftmax[i - 1], height[i]);
        rightmax[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; --i) rightmax[i] = max(rightmax[i + 1], height[i]);
        for (int i = 0; i < len; ++i) res += min(leftmax[i], rightmax[i]) - height[i];
        return res;
    }
};

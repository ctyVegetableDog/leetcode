//two pointer

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, l = height.size();
        int bottom = l - 1;
        for (int i = 0, j = l-1; i < j; ) {
            res = max(res, min(height[i], height[j]) * bottom);
            if (height[i] > height[j]) j--;
            else i++;
            bottom--;
        }
        return res;
    }
};

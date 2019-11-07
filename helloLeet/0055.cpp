//greedy(good ques)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.empty()) return false;
        int l = nums.size();
        if (l == 1) return true;
        int mx = nums[0];
        for (int i = 0; i < l - 1; i ++) {
            if (mx < i) return false;
            mx = max(mx, (i + nums[i]));
        }
        return mx >= (l - 1);
    }
};

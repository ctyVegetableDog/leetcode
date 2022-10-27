// 数组元素积的符号

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ok = 1;
        for (int i : nums) {
            if (i == 0) ok = 0;
            else if (i < 0) ok = -ok;
        }
        return ok;
    }
};

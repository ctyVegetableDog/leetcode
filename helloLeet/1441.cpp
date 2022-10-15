// 用栈操作构建数组

/*
 *没啥好说的..
 * */

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 1, len = target.size();
        vector<string> ans;
        for (int i = 0; i < len; ++i) {
            while (cur < target[i]) {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    ++cur;
                }
            ans.push_back("Push");
            ++cur;
        }
        return ans;
    }
};

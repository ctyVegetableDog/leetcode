// jump2
//
// 假设现在处于位置i，可以移动的步数是nums[i]，也就是说，在(i + 1) ~ (i + nums[i])的位置之间选一个位置作为下一步的位置。
// 也就是说，在这些位置中寻找一个能走的最远的位置，也就是j + nums[j](j:[i + 1, i + nums[i]])最大的位置。
// 举个例子 2 3 1 8 1 1 1 1 1 1 1 2
// 在最开始2的位置，可以走到3或者1，如果走到3，下次可以选择的位置是1，8，1，如果选择1，下次只能选8，虽然这两个，在当前状态下都能选到最好的，但是走到1之后可以选择的点，走到3都能选，所以直接贪心j + nums[j]最大的就行
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, end = 0, pos = 0, tar = nums.size();
        for (int i = 0; i < tar - 1; ++i) {
            pos = max(pos, i + nums[i]);
            if (i == end) {
                end = pos;
                ans++;
            }
        }
        return ans;
    }
};

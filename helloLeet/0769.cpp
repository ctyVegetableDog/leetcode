class Solution {
public:
    /*
    因为没有重复数据且数据满足0 <= arr[i] <= n，所以意味着排完序之后必然是0,1,2,3...n
    可以维护一个最大值表示当前扫描到的数的最大值mx，当扫描到某下标i时，如果有i == mx，说明目前维护的区间内所有数都小于i，并且已经包含所有小于等于i的数了
    */
    int maxChunksToSorted(vector<int>& arr) {
        int mx = -1, ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            mx = max(mx, arr[i]);
            if (i == mx) ++ans;
        }
        return ans;
    }
};

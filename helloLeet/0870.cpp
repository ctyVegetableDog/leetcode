// 优势洗牌

/*
 *经典一秒想思路，半天想实现
 根据值对索引排序
 * */

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int len = nums2.size();
        vector<int> ans(len);
        vector<int> idx1;
        vector<int> idx2;
        for (int i = 0; i < len; ++i) {
            idx1.push_back(i);
            idx2.push_back(i);
        }
        // 按照数据生序对下标排序
        sort(idx1.begin(), idx1.end(), [&](int i, int j) {return nums1[i] < nums1[j];});
        sort(idx2.begin(), idx2.end(), [&](int i, int j) {return nums2[i] < nums2[j];});
        for (int i = 0, j = 0, k = len - 1; i < len;++i) {
            if (nums1[idx1[i]] > nums2[idx2[j]]) {
                ans[idx2[j]] = nums1[idx1[i]];
                ++j;
            } else {
                ans[idx2[k]] = nums1[idx1[i]];
                --k;
            }
        }
        return ans;
    }
};

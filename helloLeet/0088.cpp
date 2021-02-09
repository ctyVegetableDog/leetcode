//Merge two array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m - 1, q = n - 1, k = m + n - 1;
        while (q >= 0) {
            if (p >= 0 && nums1[p] > nums2[q]) nums1[k--] = nums1[p--];
            else nums1[k--] = nums2[q--];
        }
    }
};

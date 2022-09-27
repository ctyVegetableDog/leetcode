// 两个数组的中位数

class Solution {
public:
    /*
    该问题等价于等两个数组合并的数组中第k小的数
    每次分别取两个数组第k/2位的数，比较小的一方小的那k/2个数必然不是第k小的数，假设两个数为a,b，比a小的有k/2个，比b小的也有k/2个，此时若a < b，则a必然落在比b小的那k/2个数的区间内，即所有比a还小的数必然不满足比它小的数有k个
    这样相当于排除了所有比a小的那k/2个数，此时问题转化为，在a,b构成的联合数组中先去掉了k/2个数，此时找第k - k / 2小的数， 即k = k - k / 2
    以此类推，直到变为找最小的数，此时比较a,b就行了
    当某一方数组长度被排除到小于k/2时，那么此时第k小的数必然不在其中，直接选择另一个数组中第k小的数就行了
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        代码是用的某个大佬的题解，写得太优雅了
        另外这题 +1 -1很绕人，要多理解几遍
        */
        int n = nums1.size(), m = nums2.size();
        int left = (n + m + 1) / 2; //如果n + m是奇数则是中位数，是偶数则是中间两个数左边的那个
        int right = (n + m + 2) / 2;//如果n + m是奇数则是中位数，是偶数则是中间两个数右边的那
        return (helper(nums1, 0, n - 1, nums2, 0, m - 1, left) + helper(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
    }

    int helper(const vector<int>& nums1, int start1, int end1, const vector<int>& nums2, int start2, int end2, int k) {
        int len1 = end1 - start1 + 1; // 分别取当前两个数组的长度
        int len2 = end2 - start2 + 1;
        if (len1 > len2) return helper(nums2, start2, end2, nums1, start1, end1, k); // 如果len1比len2长则交换位置，保证len1永远是更短的那个
        if (len1 == 0) return nums2[start2 + k - 1]; // 如果短的那方到头了，那直接返回长的那方的第k个数，这里-1是因为k是个数，将其转化为索引需要-1，因为数k个数start2自己也是一个位置

        if(k == 1) return min(nums1[start1], nums2[start2]); // 如果k递归到1，说明找当前最小的那个数，即两个数组的第一位
        
        int mid1 = start1 + min(len1, k / 2) - 1; // 如果某数组的当前长度不足k / 2，则直接考察最后一个， 这里-1是因为start1自己也算一个位置
        int mid2 = start2 + min(len2, k / 2) - 1;
        
        if (nums1[mid1] > nums2[mid2]) {
            return helper(nums1, start1, end1, nums2, mid2 + 1, end2, k - (mid2 - start2 + 1)); // k - (mid2 - start2 + 1)，这里 k减去可以排出元素的个数，比如3号到5号都可以排出，实际排除了3个即5 - 3 + 1个
        } else {
            return helper(nums1, mid1 + 1, end1, nums2, start2, end2, k - (mid1 - start1 + 1));
        }
    }
};

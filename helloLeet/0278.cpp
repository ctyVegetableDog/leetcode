// first bad version
// 二分左边界
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid + 1)) right = mid;
            else left = mid + 1;
        }
        return left + 1;
    }
};

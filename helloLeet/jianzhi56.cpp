// single numbers
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;
        for (int i : nums) x ^= i; // 拿到两个数的异或
        int mask = 1;
        while ((mask & x) == 0) mask <<= 1; // 拿到xor的右数第一个1（其实随便一个）
        int a = 0, b = 0;
        for (int i : nums) { // 本质上是将nums里的元素分为两组，使其满足1.a和b在不同组 2.相同的数字在相同组
        // 因为mask是x的第一位1，而x是a,b的异或，所以a和b在mask位必然是不同，所以必然被分到两组
        // 因为相同数字的mask位必然是相同的，所以也会被分到一组
            if (i & mask) a ^= i; 
            else b ^= i;
        }
        return {a, b};
    }
};

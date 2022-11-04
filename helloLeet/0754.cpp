// 到达终点数字

class Solution {
    // 因为负数和正数情况一样，所以取target绝对值算就行
    // 一直往前走直到超过或等于target，假设走了n步，和为cur此时
    // 若等于target直接返回n
    // 若多出的部分是偶数，假设是d，那么可以改变第d/2步的方向，此时cur - (d/2) * 2为target，一步不用多走，还是返回n
    // 若多出的是奇数，此时必然有n + 2步的办法，先往前走一步，再往回走一步，相当于cur - 1，然后cur变为偶数
    // 也可能有n + 1步的方法，此时不可能是再往回走一步（因为这样cur将小于target），只可能往前走一步，此时超过了target的d + n + 1，若这个数是偶数则可以改变(d + n + 1) / 2步的方向，因为(d + n + 1)/2 <= n，所以第(d + n + 1)/2肯定存在
public:
    int reachNumber(int target) {
        if (target < 0) target = -target;
        int n = 0, cur = 0;
        while (cur < target) {
            ++n;
            cur += n;
        }
        if (cur == target || (cur - target) % 2 == 0) return n;
        if ((cur - target + n + 1) % 2 == 0) return n + 1;
        return n + 2;
    }
};

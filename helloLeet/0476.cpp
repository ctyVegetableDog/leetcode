// find complement
// lowbit x & -x / x & (x ^ (x - 1))
class Solution {
public:
    int findComplement(int num) {
        int helper = 0;
        for (int i = num; i != 0; i -= (i & -i)) helper = i;
        return ~num & (helper - 1);
    }
};

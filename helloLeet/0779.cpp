// 第k个语法符号

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        int temp = pow(2, n - 1) / 2;
        if (k <= temp) return kthGrammar(n - 1, k);
        else return !kthGrammar(n - 1, k - temp);
    }
};

/*
	method1:recursion x^n == (n%2 == 0) ? (x*x)^n/2 : ((x*x)^n/2)*x
	method2: binary (not understand yet)
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) return myPow(x * x, n/2);
        if (n < 0) {
            x = 1/x;
            n = -n;
        }
        if (x == 0) return 0;
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        if (n % 2 == 0) return myPow(x * x, n / 2);
        else return myPow(x * x, n / 2) * x;
    }
};

//check if a num is a power of 2
/*
	this solution is from other person, if a num is power of 2, which means only one bit of n is 1, and for n-1, all of the bits r 1 (4 = 100, 3 = 011) , which means n&(n-1) must be 0
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && !(n&(n-1)));
    }
};

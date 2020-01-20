//sum of two integers by bit oper

/*
	when (a & b) is negative, recursion will run forever, the only thing we have to do is just keep it positive
*/

class Solution {
public:
    
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (unsigned int)(a & b) << 1);
    }
};

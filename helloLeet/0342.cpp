//Power of four

/*
	check if a number is power of 4
	if a number is power of 4, it must be a power of 2, which means num >0 && !(num & (num - 1))
	
	4^n - 1 = (2^n^2 - 1^2) = (2^n + 1) * (2^n - 1)
	In 3 consecutive number, there must be one that is a multiple of 3
	So in (2^n - 1), 2^n, (2^n + 1), 2^n can't be a that number, which means in (2^n + 1) and (2^n -1), there must be a multiple of 3, so 4^n - 1 must be a multiple of 3
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && !((num - 1) % 3);
    }
};

//Single Number 2(bit, good question)

/*
	every element appears 3 times except one, find the single one.
	as we know x ^ 0 = x, x ^ x = 0
	so we have to find a method, that make a number become itself when it appear once, and become 0 when it appear 3 times
	so we use 2 numbers and initialize them with 0 called one and two
	a.when the number appear once:
	  one = ~two & (one ^ n)
	  one ^ n = n(as one is 0), ~two = INT_MAX(as two is 0), so one = ~two & (one ^ n) = n
	  two = ~one & (two ^ n)
	  two ^ n = n, ~one = ~n(as one = n), so two = ~n & n = 0
	b.when the number appear twice:
	  one = ~two & (one ^ n)
	  one ^ n = 0(one = n), ~two = INT_MAX, so one = INT_MAX & 0 = 0
	  two = ~one & (two ^ n)
	  two ^ n = n, ~one = INT_MAX, so two = INT_MAX & n = n
	c.when the number appear 3 times
	  one = ~two & (one ^ n)
	  one ^ n = n(one = 0), ~two = ~n(two = n), one = ~n & n = 0
	
	as this method obey the exchange rule (not matter the order that numbers appear in vector), one will be the single number after traverse
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int one = 0, two = 0;
        for (int n : nums) {
            one = ~two & (one ^ n);
            two = ~one & (two ^ n);
        }
        return one;
    }
};

//bitwise AND of numbers range

/*
	for range [m,n]
	if (m != n), then in [m,n] must be a odd-even pair, make the result's last bit become 0, so we can soulution it recursively, find all the 0 bits by keep moving m and n right a position
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;
        else return rangeBitwiseAnd(m/2, n/2) << 1;
    }
};

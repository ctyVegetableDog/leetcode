//Reverse Bits

/*
	first solution is based on bit operation
	(n >> (31 - i) & 1) is get the ith bit in number n(left to right)
	n = 1101
	i = 3 n>>(3 - 3) & 1 = n & 1 = 1101 & 0001 = 0001
	i = 2 n>>(3 - 2) & 1 = 0110 & 0001 = 0000
	i = 1 n>>(3 - 1) & 1 = 0011 & 0001 = 0001
	i = 0 n>>(3 - 0) & 1 = 0001 & 0001 = 0001

	<<i is set ith bit to (31 - i)th
	set 31th to 0th, set 30th to 1th
	1101(take 4 bits as instance): 
	0001->1000//move 3 bits
	0000->0000//move 2 bits
	0001->0010//move 1 bit
	0001->0001

	res |= is set nth bit
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 31; i >= 0; --i)
            res |= (n >> (31 - i) & 1) << i;
        return res;
    }
};

/*
	another is use bitset
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bs(n);
        for (int i = 0; i < 32 / 2 ; ++i) {
            bool temp = bs[i];
            bs[i] = bs[31 - i];
            bs[31 - i] = temp;
        }
        return static_cast<uint32_t>(bs.to_ulong());
    }
};

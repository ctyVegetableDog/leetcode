//reverse string 2

/*
	min() is the iteration
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k)
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        return s;
    }
};

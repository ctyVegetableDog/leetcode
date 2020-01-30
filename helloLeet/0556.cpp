//Next greater element3 (next_permulation)

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end()); 
        long res = atoi(s.c_str());
        return res > n ? res : -1;
    }
};

// monotonic sequence
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        if (len == 1) return true;
        bool inc = true, dec = true;
        for (int i = 0; i < len - 1; ++i) {
            if (A[i + 1] > A[i]) dec = false;
            if (A[i + 1] < A[i]) inc = false;
        }
        return inc || dec;
    }
};

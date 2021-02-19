// Max consist 1
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0, z = 0;
        for (int l = 0, r = 0; r < A.size(); ++r) {
            if (A[r] == 0) ++z;
            while (z > K) {
                if (A[l++] == 0) --z;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

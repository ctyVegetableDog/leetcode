// Min flip times
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        std::queue<int> q;
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (!q.empty() && i >= q.front() + K) {
                q.pop();
            }
            if (q.size() % 2 == A[i]) {
                if (i + K > A.size()) {
                    return -1;
                }
                res++;
                q.push(i);
            }
        } 
        return res;
    }
};

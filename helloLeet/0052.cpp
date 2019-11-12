//totally same as 0051

class Solution {
public:
    
    int res = 0;
    vector<int> pos;
    void addQ(int n, int t, vector<int>& pos) {
        if (n == t) {//already put t Qs
            res ++;
            return;
        }
        int l = pos.size();
        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int p = 0; p < l; p++) {//tp ipos[p]
                if (i == pos[p] || abs(t - p) == abs(i - pos[p])) {     
                    ok = false;
                    break;
                }
            }
            if (ok) {
                pos.push_back(i);
                addQ(n, t + 1, pos);
                pos.pop_back();
            }
        }
    }
    
    int totalNQueens(int n) {
        addQ(n, 0, pos);
        return res;
    }
};

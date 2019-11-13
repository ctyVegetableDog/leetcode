//backtracking	(ques is simple, sth is important is take vector as a para is too costly, meanwhile, push and pop r costly as well, use resize() before oper and just change elements could be faster)

class Solution {
public:
    vector<vector<int> > res;
    vector<int> cur;
    void getRes(int n, int k, int st, int ix) {
        if (k == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = st; i <= n; i ++) {
            cur[ix] = i;
            getRes(n, k - 1, i + 1, ix + 1);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        cur.resize(k);
        getRes(n, k, 1, 0);
        return res;
    }
};

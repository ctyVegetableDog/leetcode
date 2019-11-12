//backtracking (N Queens)

class Solution {
public:
    vector<vector<string> > res;
    vector<int> pos;
    void addQ(int n, int t, vector<int>& pos) {
        if (n == t) {//already put t Qs
            vector<string> cur_line;
            for (int i = 0; i < n; i++) {
                string s = "";
                for (int j = 0; j < n; j++) {
                    if (i == pos[j]) s += 'Q';
                    else s += '.';
                }
                cur_line.push_back(s);
            }
            res.push_back(cur_line);
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
    vector<vector<string>> solveNQueens(int n) {
        addQ(n, 0, pos);
        return res;
    }
};

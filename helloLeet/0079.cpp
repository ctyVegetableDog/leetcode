//dfs (good ques)

class Solution {
public:
    bool dfs(vector<vector<char> >& board, string& tar, int i, int j, int pos) {
        if (pos == tar.size()) return true;
        if (i < 0 || j <0 || i >= board.size() || j >= board[0].size()) return false;
        if (board[i][j] == '0' || board[i][j] != tar[pos]) return false;
        board[i][j] = '0';
        bool res = dfs(board, tar, i - 1, j, pos + 1) || dfs(board, tar, i + 1, j, pos + 1) || dfs(board, tar, i, j + 1, pos + 1) || dfs(board, tar, i, j - 1, pos + 1);
        board[i][j] = tar[pos];
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        if (board[0].empty()) return false;
        for (int i = 0;i < board.size();i ++) {
            for (int j = 0; j < board[0].size();j++)
                if (dfs(board, word, i, j, 0)) return true;
        }
        return false;
    }
};

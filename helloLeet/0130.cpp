//Surrounded Regions (dfs)

class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i >= 0 && i < board.size() && j >=j && j < board[0].size() && board[i][j] == 'O') {
            board[i][j] = '1';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        for (int i = 0; i < board.size(); ++i) {
            dfs(board, i, 0);
            dfs(board, i, board[0].size() - 1);
        }
        for (int j = 0; j < board[0].size(); ++j) {
            dfs(board, 0, j);
            dfs(board, board.size() - 1, j);
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
        return;
    }
};

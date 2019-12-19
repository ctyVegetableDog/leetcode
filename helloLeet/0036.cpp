//valid Sudoku (hash)

class Solution {
public:
    
    bool checkAPart(vector<vector<char>>& board, int r, int c) {
        bool mp[10];
        memset(mp, false, sizeof(mp));
        for (int j = r; j < r + 3; j++) {
            for (int k = c; k < c + 3; k++) {
                if (board[j][k] >= '0' && board[j][k] <= '9') {
                    if (mp[board[j][k] - '0']) return false;
                    mp[board[j][k] - '0'] = true;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool mp[10];
        for (int i = 0; i < 9; i++) {
            memset(mp, false, sizeof(mp));
            for (int j = 0; j < 9; j++) {
                if (board[i][j] >= '0' && board[i][j] <= '9') {
                    if (mp[board[i][j] - '0']) return false;
                    mp[board[i][j] - '0'] = true;
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            memset(mp, false, sizeof(mp));
            for (int j = 0; j < 9; j++) {
                if (board[j][i] >= '0' && board[j][i] <= '9') {
                    if (mp[board[j][i] - '0']) return false;
                    mp[board[j][i] - '0'] = true;
                }
            }
        }
        
        return checkAPart(board, 0, 0) && checkAPart(board, 0, 3) && checkAPart(board, 0, 6) && checkAPart(board, 3, 0) && checkAPart(board, 3, 3) && checkAPart(board, 3, 6) && checkAPart(board, 6, 0) && checkAPart(board, 6, 3) && checkAPart(board, 6, 6); 
    }
};

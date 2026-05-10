class Solution {
public:
    bool isSafe(int row, int col, char curr, vector<vector<char>>& board) {
        // row check
        for (int i = 0; i < board[0].size(); i++) {
            if (board[row][i] == curr)
                return false;
            if (board[i][col] == curr)
                return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == curr)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char curr = '1'; curr <= '9'; curr++) {
                        if (isSafe(i, j, curr, board)) {
                            board[i][j] = curr;
                            bool res = (solve(board));
                            if (res)
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
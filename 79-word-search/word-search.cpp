class Solution {
public:
    bool f(int row, int col, int idx, string word, vector<vector<char>>& board,
           vector<vector<int>>& vis) {
        if (idx == word.size())
            return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
            return false;
        if (word[idx] != board[row][col])
            return false;

        int up = false;
        int down = false;
        int right = false;
        int left = false;

        if (idx == word.size() - 1)
            return true;
        vis[row][col] = 1;

        if (row - 1 >= 0 && vis[row - 1][col] != 1) {

            up = f(row - 1, col, idx + 1, word, board, vis);
        }

        if (row + 1 < board.size() && vis[row + 1][col] != 1) {

            down = f(row + 1, col, idx + 1, word, board, vis);
        }
        if (col - 1 >= 0 && vis[row][col - 1] != 1) {

            left = f(row, col - 1, idx + 1, word, board, vis);
        }
        if (col + 1 < board[0].size() && vis[row][col + 1] != 1) {

            right = f(row, col + 1, idx + 1, word, board, vis);
        }
        vis[row][col] = 0;

        return up || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (word.size() == 1)
                        return true;
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    bool res = f(i, j, 0, word, board, vis);
                    if (res)
                        return true;
                }
            }
        }
        return false;
    }
};
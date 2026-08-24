class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    bool dfs(int row, int col, int idx, vector<vector<char>>& board,
             string word, int n, int m) {
        if (row > n || col > m)
            return false;
        if (idx == word.size())
            return true;

        for (int j = 0; j < 4; j++) {
            int nRow = row + dx[j];
            int nCol = col + dy[j];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                board[nRow][nCol] == word[idx] && board[nRow][nCol] != '.') {
                char org = board[nRow][nCol];
                board[nRow][nCol] = '.';
                if (dfs(nRow, nCol, idx + 1, board, word, n, m))
                    return true;
                board[nRow][nCol] = org;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    char org = board[i][j];
                    board[i][j] = '.';
                    bool ans = dfs(i, j, 1, board, word, n, m);
                    if (ans)
                        return true;
                    board[i][j] = org;
                }
            }
        }
        return false;
    }
};
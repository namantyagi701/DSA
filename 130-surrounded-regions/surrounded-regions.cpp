class Solution {
public:
    void dfs(int i , int j , vector<vector<char>>& board){
        board[i][j] = '1';

        if(i+1 < board.size() && board[i+1][j] == 'O') dfs(i+1 , j , board);
        if(j+1 < board[0].size() && board[i][j+1] == 'O') dfs(i , j+1 , board);
        if(i-1 >= 0 && board[i-1][j] == 'O') dfs(i-1 , j , board);
        if(j-1 >= 0 && board[i][j-1] == 'O') dfs(i , j-1 , board);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        // vector<vector<int>> ans(n , vector<int>(m , 0));
        for(int i = 0 ;  i < n ; i++){
            if(board[i][0] == 'O'){
                dfs(i , 0 , board);
            }
            if(board[i][m-1] == 'O'){
                dfs(i , m-1 , board);
            }
        }
        for(int j = 0 ; j < m ; j++){
            if(board[0][j] == 'O'){
                dfs(0 , j , board);
            }
            if(board[n-1][j] == 'O'){
                dfs(n-1 , j , board);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] != '1') board[i][j] = 'X';
                else board[i][j] = 'O';
            }
        }
    }
};
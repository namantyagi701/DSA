class Solution {
public:
    bool isSafe(int row , int col , vector<string> &board){
        for(int i = row - 1 ; i >= 0 ; i--){
            if(board[i][col] == 'Q') return false;
        }

        int i = row - 1;
        int j = col - 1;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = row - 1;
        j = col + 1;

        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    void f(int idx , int n ,vector<string> &board, vector<vector<string>>&ans){
        if(idx == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(isSafe(idx , i , board)){
                board[idx][i] = 'Q';
                f(idx +1 , n , board , ans);
                board[idx][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n , string(n, '.'));

        f(0 , n , board , ans);
        return ans;
    }
};
class Solution {
public:
    void dfs(int row , int col ,vector<vector<int>>& grid ,vector<vector<int>> &vis, int dx[] , int dy[]){

        vis[row][col] = 1;

        for(int i = 0 ; i < 4 ; i++){
            int nRow = row + dx[i];
            int nCol = col + dy[i];
            if(nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() && grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0){
                dfs(nRow , nCol , grid , vis , dx , dy);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1 , 0 , 1 , 0};
        int dy[] = {0 , 1 , 0 , -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0 ; i < n ; i++){
            //first col
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i , 0 , grid , vis , dx , dy);
            }
            //last col
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i , m-1 , grid , vis , dx , dy);
            }
        }

        for(int j = 0 ; j < m ; j++){
            //first row
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0 , j , grid , vis , dx , dy);
            }
            //last row
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                dfs(n-1 , j , grid , vis , dx , dy);
            }
        }
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) count++;
            }
        }
        return count;
    }
};
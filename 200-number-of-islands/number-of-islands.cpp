class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    void dfs(int row, int col, vector<vector<char>>& grid,vector<vector<int>>& vis) {
        vis[row][col] = 1;
        for(int i = 0 ; i < 4 ; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && vis[nrow][ncol] == 0 && grid[nrow][ncol] == '1'){
                dfs(nrow , ncol , grid , vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               if (grid[i][j] == '1' && vis[i][j] != 1) {
                    count++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));

        queue<pair<int , int>>q;
        int dx[] = {-1 , 0 , 1 , 0};
        int dy[] = {0 , 1 , 0 , -1};
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    count++;
                    q.push({i , j});
                    while(!q.empty()){
                        auto curr = q.front();
                        int row = curr.first;
                        int col = curr.second;
                        q.pop();
                        vis[row][col] = 1;
                        for(int ii = 0 ; ii < 4 ; ii++){
                            int nRow = row + dx[ii];
                            int nCol = col + dy[ii];
                            if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m && vis[nRow][nCol] == 0 && grid[nRow][nCol] == '1'){
                                vis[nRow][nCol] = 1;
                                q.push({nRow , nCol});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
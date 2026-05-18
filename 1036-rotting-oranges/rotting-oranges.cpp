class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }
        int time = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            time = curr.first;

            int row = curr.second.first;
            int col = curr.second.second;

            for (int i = 0; i < 4; i++) {
                int nRow = row + dx[i];
                int nCol = col + dy[i];
                if(nRow < n && nRow >= 0 && nCol < m && nCol >= 0 && grid[nRow][nCol] == 1 && vis[nRow][nCol] != 1){
                    vis[nRow][nCol] = 1;
                    q.push({time + 1 , {nRow , nCol}});
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) return -1;
            }
        }
        return time;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == 2)
                q.push({0, {i, j}});
            }
        }
        int maxTime = 0;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        while (!q.empty()) {
            // int size = q.size();
            auto curr = q.front();
            q.pop();
            int time = curr.first;
            maxTime = max(maxTime , time);
            int row = curr.second.first;
            int col = curr.second.second;
            for(int k = 0 ; k < 4 ; k++){
                int nRow = row + dx[k];
                int nCol = col + dy[k];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0){
                q.push({time+1,{nRow , nCol}});
                vis[nRow][nCol] = 1;}
            }
        }
        bool fl = true;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    fl = false;
                    break;
                }
            }
        }
        return fl ? maxTime : -1;
    }
};
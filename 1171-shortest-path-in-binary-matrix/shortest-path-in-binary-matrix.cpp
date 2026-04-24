class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int, pair<int,int>>> q;
        q.push({1, {0, 0}});  

        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;

        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n-1 && col == n-1)
                return dist;

            for (int i = 0; i < 8; i++) {
                int nRow = row + dx[i];
                int nCol = col + dy[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                    grid[nRow][nCol] == 0 && !vis[nRow][nCol]) {
                    
                    vis[nRow][nCol] = 1;
                    q.push({dist + 1, {nRow, nCol}});
                }
            }
        }

        return -1;
    }
};
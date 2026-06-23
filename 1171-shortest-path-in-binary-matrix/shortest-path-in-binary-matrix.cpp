class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[n - 1][n - 1] != 0 || grid[0][0] != 0)
            return -1;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> minDis(n, vector<int>(n, 0));
        q.push({1, {0, 0}});
        minDis[0][0] = 1;
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (!q.empty()) {
            auto ele = q.front();
            q.pop();
            int dist = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;
            if(row == n-1 && col == n-1) return dist;

            for (int i = 0; i < 8; i++) {
                int nRow = row + dx[i];
                int nCol = col + dy[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                    grid[nRow][nCol] == 0) {
                    if (minDis[nRow][nCol] == 0) {
                        minDis[nRow][nCol] = 1;
                        q.push({1 + dist , {nRow, nCol}});
                    }
                }
            }
        }
        return -1;
    }
};
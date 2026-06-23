class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[n - 1][n - 1] != 0 || grid[0][0] != 0)
            return -1;
        set<pair<int, pair<int, int>>> st;
        vector<vector<int>> minDis(n, vector<int>(n, INT_MAX));
        st.insert({1, {0, 0}});
        minDis[0][0] = 1;
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while (!st.empty()) {
            auto ele = *st.begin();
            st.erase(st.begin());
            int dist = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;

            for (int i = 0; i < 8; i++) {
                int nRow = row + dx[i];
                int nCol = col + dy[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                    grid[nRow][nCol] == 0 && grid[nRow][nCol] == 0) {
                    if (minDis[nRow][nCol] > 1 + dist) {
                        if(minDis[nRow][nCol] != INT_MAX) {
                            st.erase({minDis[nRow][nCol], {nRow, nCol}});
                        }
                        minDis[nRow][nCol] = 1 + dist;
                        st.insert({1 + dist, {nRow, nCol}});
                    }
                }
            }
        }
        if (minDis[n - 1][n - 1] == INT_MAX)
            return -1;
        return minDis[n - 1][n - 1];
    }
};
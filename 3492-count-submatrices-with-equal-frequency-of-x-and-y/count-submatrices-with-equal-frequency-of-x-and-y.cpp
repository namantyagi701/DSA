class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> arr(n, vector<int>(m, -1));
        vector<vector<int>> xPrefix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X') {
                    arr[i][j] = 1;
                    xPrefix[i][j] = 1;
                } else if (grid[i][j] == 'Y')
                    arr[i][j] = -1;
                else
                    arr[i][j] = 0;
            }
        }
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    arr[i][j] = arr[i][j];
                    xPrefix[i][j] = xPrefix[i][j];
                } else if (i == 0) {
                    arr[i][j] = arr[i][j - 1] + arr[i][j];
                    xPrefix[i][j] = xPrefix[i][j - 1] + xPrefix[i][j];

                } else if (j == 0) {
                    arr[i][j] = arr[i - 1][j] + arr[i][j];
                    xPrefix[i][j] = xPrefix[i - 1][j] + xPrefix[i][j];
                } else {
                    arr[i][j] = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] -
                                arr[i - 1][j - 1];
                    xPrefix[i][j] = xPrefix[i][j] + xPrefix[i - 1][j] +
                                    xPrefix[i][j - 1] - xPrefix[i - 1][j - 1];
                }

                if (arr[i][j] == 0 && xPrefix[i][j] >= 1)
                    cnt++;
            }
        }
        return cnt;
    }
};
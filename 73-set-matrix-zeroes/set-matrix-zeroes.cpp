class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<pair<int, int>> vect;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    vect.push_back({i, j});
                }
            }
        }
        unordered_set<int> rowst;
        unordered_set<int> colst;
        for (auto it : vect) {
            int row = it.first;
            int col = it.second;
            if (rowst.find(row) == rowst.end()) {
                for (int i = 0; i < m; i++) {
                    matrix[row][i] = 0;
                }
                rowst.insert(row);
            }
            if (colst.find(col) == colst.end()) {
                for (int i = 0; i < n; i++) {
                    matrix[i][col] = 0;
                }
                colst.insert(col);
            }
        }
    }
};
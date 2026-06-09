class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0, j = m - 1;
        vector<int> arr(2);

        while (i < n && j > 0) {
            if (i < n - 1 && mat[i][j] < mat[i + 1][j]) {
                i++;
            }
            else if (mat[i][j] < mat[i][j - 1]) {
                j--;
            }
            else {
                arr[0] = i;
                arr[1] = j;
                break;
            }
        }

        if (j < m - 1 && mat[i][j + 1] > mat[i][j]) {
            arr[1] = j + 1;
        }

        if (i < n - 1 && mat[i + 1][j] > mat[i][j]) {
            arr[0] = i;
        }

        return arr;
    }
};
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        vector<vector<int>>temp(k , vector<int>(k , 0));
        for (int i = x; i < x + k ; i++) {
            for (int j = y; j < y + k ; j++) {
               temp[i-x][j-y] = grid[i][j];
            }
        }
        reverse(temp.begin() , temp.end());
        for (int i = x; i < x + k ; i++) {
            for (int j = y; j < y + k ; j++) {
               grid[i][j]= temp[i-x][j-y] ;
            }
        }
        return grid;
        
    }
};
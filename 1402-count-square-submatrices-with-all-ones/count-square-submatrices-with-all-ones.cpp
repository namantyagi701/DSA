class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>arr = matrix;
        int mini = 0;
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
               if(arr[i][j] == 1){
               mini = min({arr[i-1][j] , arr[i-1][j-1] , arr[i][j-1]});
               arr[i][j] = 1 + mini;
               }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
               ans += arr[i][j];
            }
        }
        return ans;
    }
};
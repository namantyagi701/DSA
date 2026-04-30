class Solution {
public:
    int f(int i , int j ,vector<vector<int>>& grid, int k, vector<vector<vector<int>>> &dp){
        if(i < 0 || j < 0) return INT_MIN;
         if(k < 0) return  INT_MIN;
        if(i == 0  && j == 0){
            if(k == 0 && grid[i][j] == 0) return 0;
            if(k > 0 && grid[i][j]!= 0) return grid[i][j];
            return 0;
        }
       
        
        if(dp[i][j][k] != -1) return dp[i][j][k];

        int val = grid[i][j];
        int pen = 0;
        if(val > 0) pen = 1;

        int up = grid[i][j] + f(i-1 , j , grid , k  - pen ,dp);
        int left = grid[i][j] + f(i , j-1 , grid , k  - pen, dp);

        return dp[i][j][k] = max(up , left);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(k + 1 , -1)));
        int ans = f(m -1 , n-1 , grid ,k , dp);
        if(ans < 0) return -1;
        return ans;
    }
};
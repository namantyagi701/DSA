class Solution {
public:
    int d[3] = {-1  , 0 , 1};
    int f(int i , int j1 , int j2 , vector<vector<int>>& grid , int n , int m , vector<vector<vector<int>>> &dp){
        if(i >= n || j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) return INT_MIN;
        if(i == n-1){
            if(j1 != j2) return grid[i][j1] + grid[i][j2];
            return grid[i][j1];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = 0;
        int curr = 0;
        if(j1 == j2){
            curr = grid[i][j1];
        }  
        else{
            curr = grid[i][j1] + grid[i][j2];
        }
        for(int x = 0 ; x < 3 ; x++){
            for(int y = 0 ; y < 3 ; y++){
                int currj1 = j1 + d[x];
                int currj2 = j2 + d[y];
                
                maxi = max(maxi , curr + f(i+1 , currj1 , currj2 ,grid ,n, m , dp));
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(m ,vector<int>(m , -1)));
        return f(0 , 0 , m-1 , grid , n , m , dp);
    }
};
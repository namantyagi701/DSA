class Solution {
public:
    vector<int>dx = {-1 , 0 , 1};
    int f(int i , int j1 , int j2 , int n , int m ,vector<vector<int>>& grid , vector<vector<vector<int>>> &dp){
        if(i == n-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int ans = -1e7;
        int curr = 0;
        if(j1 == j2){
            curr = grid[i][j1];
        }
        else{
            curr = grid[i][j1] + grid[i][j2];
        }
        for(int k = 0 ; k < 3 ; k++){
            for(int y = 0 ; y < 3 ; y++){
                int n1 = j1 + dx[k];
                int n2 = j2 + dx[y];
                if(n1 >= 0 && n1 < m && n2 >= 0 && n2 < m)
                ans = max(ans , curr + f(i+1 , n1 , n2, n , m , grid , dp));
            }
        }
        return dp[i][j1][j2] = ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m , vector<int>(m , -1)));
        return f(0 , 0 , m-1 , n , m , grid,dp);
    }
};
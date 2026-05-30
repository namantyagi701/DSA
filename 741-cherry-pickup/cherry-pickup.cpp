class Solution {
public:
    int f(int i1 , int j1 , int i2 ,vector<vector<int>>& arr , int n , vector<vector<vector<int>>> &dp){
        int j2 = i1 + j1 - i2;
        if(i1 >= n || j1 >= n || i2 >= n || j2 >= n || arr[i1][j1] == -1 || arr[i2][j2] == -1) return -1e9;

        if(i1 == n-1 && j1 == n-1) return arr[i1][j1];
        if(dp[i1][j1][i2] != -1) return dp[i1][j1][i2];
        
        int curr = arr[i1][j1];
        if(i1 != i2){
           curr += arr[i2][j2];
        }
        
        int ans = max({
            f(i1 + 1 , j1 , i2 + 1  , arr , n,dp),f(i1 , j1 + 1 , i2 , arr , n,dp),f(i1 + 1 , j1 , i2 , arr , n,dp),f(i1 , j1 + 1 , i2 + 1 , arr , n , dp)
        });
        
        return dp[i1][j1][i2] = curr + ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(n+1 , vector<int>(n+1 , -1)));
        int ans = f(0,0,0,grid,n ,dp);
        return max(0 ,ans);
    }
};
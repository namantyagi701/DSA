class Solution {
public:
    int f(int i , int j , vector<vector<int>>& arr , vector<vector<int>> &dp){
        if(i >= arr.size() || j >= arr[0].size()) return INT_MAX;
        if(i == arr.size()-1 && j == arr[0].size() -1){
            return max(1 , 1-arr[i][j]);
        }
        if(dp[i][j] != -1) return dp[i][j];
        int need = min(f(i+1 ,j , arr,dp) , f(i , j+1 , arr , dp));
        return dp[i][j] = max(1 , need - arr[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        vector<vector<int>>dp(m, vector<int>(n , -1));
        return f(0 , 0 , arr , dp);
    }
};
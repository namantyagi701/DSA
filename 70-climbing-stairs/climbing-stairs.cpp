class Solution {
// private:
//     int f(int n, vector<int>&dp){
//         if(n== 0 || n == 1) return n;
//         if(dp[n] != -1) return dp[n];
//         return dp[n] = f(n-1 , dp) + f(n-2 , dp);
//     }
public:
    int climbStairs(int n) {
        vector<int>dp(n + 2 , 0); 
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2 ; i <= n+1 ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n+1];
    }
};
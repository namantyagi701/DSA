class Solution {
public:
    int f(int i , vector<int> &nums , int prev ,  vector<vector<int>> &dp){
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        int nt = f(i+1 , nums ,prev,dp);
        int t = 0;
        if(prev == n  || nums[prev] < nums[i]){
            t = 1 + f(i+1,nums,i,dp);
        }
        return dp[i][prev] = max(t , nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));
        for(int i = n -1 ; i >= 0 ; i--){
            for(int prev = n ; prev >= 0 ; prev--){
                int nt = dp[i+1][prev];
                int t = 0;
                if(prev == n || nums[prev] < nums[i]){
                    t = 1 + dp[i+1][i];
                }
                dp[i][prev] = max(t,nt);
            }
        }
        return dp[0][n];
    }
};
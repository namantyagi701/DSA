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
        vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        return f(0 , nums , n ,dp);
    }
};
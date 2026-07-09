class Solution {
public:
    int f(int i , int n , vector<int>&nums , vector<int> &dp){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        int notTake = f(i+1 , n , nums , dp);
        int take = nums[i] + f(i+2 , n , nums,dp);
        
        return dp[i] = max(take , notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp(n ,-1);
        int ans1 = f(0 , n-1 , nums,dp);
        vector<int>dp2(n ,-1);
        int ans2 = f(1 , n, nums, dp2);
        return max(ans1 , ans2);
    }
};
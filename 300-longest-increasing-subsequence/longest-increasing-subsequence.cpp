class Solution {
public:
    int n;
    int f(int i , int prev , vector<int> &nums , vector<vector<int>> &dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        int notTake = 0 + f(i + 1 , prev , nums,dp);
        int take = 0;
        if(prev == n || nums[i] > nums[prev]){
            take = 1 + f(i + 1 , i , nums ,dp);
        }
        return dp[i][prev] = max(take , notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n+1 , -1));
        return f(0 , n , nums ,dp);
    }
};
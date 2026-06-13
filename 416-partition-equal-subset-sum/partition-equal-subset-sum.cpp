class Solution {
public:
    bool f(int i , int k , vector<int> &nums ,vector<vector<int>> &dp){
        if(k == 0) return true;
        if(i < 0 && k > 0) return false;
        if(i == 0 && nums[i] == k) return true; 
        if(dp[i][k] != -1) return dp[i][k];
        int notTake = f(i-1 , k , nums , dp);
        int take = 0;
        if(nums[i] <= k){
            take = f(i -1 , k - nums[i] , nums ,dp);
        } 
        return dp[i][k] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        int k = sum/2;
        vector<vector<int>>dp(n , vector<int>(k + 1, -1));
        if(sum % 2 != 0) return false;
        return f(n-1 , k , nums , dp);
    }
};
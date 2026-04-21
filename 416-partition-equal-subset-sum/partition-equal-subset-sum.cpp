class Solution {
public:
    bool f(int i , int sum , vector<int> &arr , vector<vector<int>> &dp){
        if(i >= arr.size() && sum > 0) return false;
        if(sum == 0) return true;
        if(sum < 0) return false;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        int notTake = f(i + 1 , sum , arr , dp);
        int take = 0;
        if(sum >= arr[i]){
            take = f(i + 1 , sum-arr[i] , arr ,dp);
        }
        return dp[i][sum] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
           sum += nums[i];
        }
        if((sum % 2) != 0) return false;
        sum = sum /2;
        vector<vector<int>>dp(n , vector<int>(sum + 1 , -1));
        return f(0 , sum, nums , dp);
    }
};
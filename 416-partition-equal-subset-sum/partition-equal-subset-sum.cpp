class Solution {
public:
    bool f(int i , int k , vector<int> &nums, vector<vector<int>> &dp){
        if(k == 0) return false;
        if(i == 0){
            if(nums[i] == k) return true;
            return false;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int nt = f(i-1 , k , nums ,dp);
        int t = 0;
        if(nums[i] <= k){
            t = f(i-1 , k -nums[i] , nums ,dp);
        }
        return dp[i][k] = t || nt;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0) return false;
        int k = sum /2;
        vector<vector<int>>dp(n+1 , vector<int>(k+1 , -1));
        return f(n-1 , k , nums , dp);
    }
};
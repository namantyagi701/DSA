class Solution {
public:
    int f(int i , vector<int> &nums , int k , vector<vector<int>> &dp){
        if(i == 0){
            if(k == 0 && nums[i] == 0) return 2;
            if(k==0 || nums[i] == k) return 1;
            return 0;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int nt = f(i-1 , nums , k ,dp);
        int t = 0;
        if(k >= nums[i]){
            t = f(i-1 , nums , k - nums[i], dp);
        }
        return dp[i][k] = t + nt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ts = 0;
        
        for(int i = 0 ; i < n ; i++){
            ts += nums[i];
        }
         if(abs(target) > ts)
            return 0;
        if((ts + target) % 2 != 0) return 0;
        int k = (ts + target)/2;
        vector<vector<int>>dp(n , vector<int>(k + 1 , -1));
        return f(n-1 , nums , k , dp);
    }
};
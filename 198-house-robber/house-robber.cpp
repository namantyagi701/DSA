class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+2, 0);
        
        for(int i = n-1 ; i >=0 ; i--){
            int notTake = dp[i+1];
            int take = nums[i] + dp[i+2];

            dp[i] = max(take , notTake);
        }

        return dp[0];
    }
};
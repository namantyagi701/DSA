class Solution {
// private:
//     int f(int i , vector<int>& nums , vector<int> &dp ){
//         if(i < 0) return 0;
//         if(dp[i] != -1) return dp[i];
//         int notTake  = f(i-1 , nums , dp);
//         int take = nums[i] + f(i-2 , nums ,dp);

//         return dp[i] = max(take , notTake);        
//     }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n , 0);
        dp[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            int notTake = dp[i-1];
            int Take = nums[i];
            if(i > 1) Take = nums[i] + dp[i-2];

            dp[i] = max(Take , notTake); 
        }
        return dp[n-1];
    }
};
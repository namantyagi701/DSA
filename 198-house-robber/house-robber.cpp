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
        if(n == 1) return nums[0];
        // vector<int>dp(n , 0);
        int prev = nums[0];
        int prev2 = 0;
        int curr = 0;

        for(int i = 1 ; i < n ; i++){

            int notTake = prev;
            int Take = nums[i];
            if(i > 1) Take = nums[i] + prev2;

            curr = max(Take , notTake); 
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
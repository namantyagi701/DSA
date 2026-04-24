class Solution {
public:
    int f(int i ,vector<int>& arr , vector<int> &dp){
        if(i >= arr.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        int notTake = f(i+1 , arr ,dp);
        int take = arr[i] + f(i + 2 , arr , dp);

        return dp[i] = max(take , notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1 , -1);
        return f(0 , nums ,dp);
    }
};
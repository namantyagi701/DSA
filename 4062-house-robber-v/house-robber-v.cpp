class Solution {
public:
    long long f(int i , vector<int>& nums, vector<int>& colors ,int n, vector<long long> &dp){
       if(i >= n) return 0;
       
       if(dp[i] != -1) return dp[i];

       long long Take;
       if(i < n-1 && colors[i] == colors[i+1]){
           Take = nums[i] + f(i+2 , nums , colors,n,dp);
       }
       else{
           Take = nums[i] + f(i+1 , nums , colors, n,dp);
       }
       long long notTake = f(i+1 , nums , colors,n,dp);

       return dp[i] = max(Take , notTake);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int prev = -1;
        int sum = 0;
        int i = 0;
        int n = nums.size();

        vector<long long>dp(n+1 , -1);
        return f(i , nums, colors , n , dp);
    }

};
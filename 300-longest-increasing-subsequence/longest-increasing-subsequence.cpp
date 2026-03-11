class Solution {
private:
    int f(int i , int prev , vector<int> &nums , vector<vector<int>> &dp){
        if(i >= nums.size()) return 0;

        int take = 0;
        if(dp[i][prev] != -1) return dp[i][prev];
;        if(prev == 0 || nums[prev - 1] < nums[i] ) take = 1 + f(i + 1 , i +1 , nums , dp);
        int notTake = 0 + f(i + 1 , prev , nums ,dp);
        return dp[i][prev] = max(take , notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int prev = 0;
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n + 1 , -1));
        return f(0 , prev , nums , dp);  
    }
};
class Solution {
public:
    int f(int i , int k , vector<int>& arr, int n , vector<int> &dp){
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        int len = 0;
        int maxi = INT_MIN;
        int ans = INT_MIN;
        int sum = 0;
        for(int j = i ; j < min(n , k + i ); j++){
            len++;
            maxi = max(maxi , arr[j]);
            sum = len * maxi + f(j+1 , k , arr,n,dp);
            ans = max(ans , sum);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n ,-1);
        return f(0 , k , arr , n, dp);
    }
};
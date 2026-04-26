class Solution {
public:
    int f(int i , int n, int k ,vector<int>& arr , vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int maxi = INT_MIN;
        int ans = 0;
        for(int x = i ; x < min(n , i + k) ; x++){
            maxi = max(maxi , arr[x]);
            int sum = (maxi *(x - i + 1)) + f(x + 1 , n , k , arr , dp);
            ans = max(ans , sum);
        }
        return dp[i] = ans;        
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n , -1);
        return f(0 , n , k , arr , dp);
    }
};
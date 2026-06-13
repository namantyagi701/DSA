class Solution {
public:
    int f(int i , int k , vector<int> &arr , vector<vector<int>> &dp){
        if(i == 0){
           if(k == 0) return 0;
           if((k % arr[i]) == 0){
              return k / arr[i];
           }
           return 1e7;
        }
        
        if(dp[i][k] != -1) return dp[i][k];

        int nt = f(i - 1 , k , arr , dp);
        int t = 1e7;
        if(k >= arr[i]){
            t = 1 + f(i , k - arr[i] , arr , dp);
        }
        return dp[i][k] = min(t , nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin() , coins.end());
        int n = coins.size();
        vector<vector<int>>dp(n , vector<int>(amount + 1 , -1));
        int ans = f(n-1 , amount , coins , dp);
        if(ans == 1e7) return -1;
        return ans;
    }
};
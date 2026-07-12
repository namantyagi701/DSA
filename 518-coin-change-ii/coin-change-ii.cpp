class Solution {
public:
    int f(int i ,int k , vector<int> &coins , vector<vector<int>> &dp){
        if(k == 0) return 1;
        if(i == 0){
            if((k % coins[i]) == 0) return 1;
            return 0;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int nt = f(i-1 , k , coins,  dp);
        int t = 0;
        if(coins[i] <= k) t = f(i, k - coins[i] , coins, dp);

        return dp[i][k] = t + nt;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1));
        return f(n-1 , amount, coins , dp);
    }
};
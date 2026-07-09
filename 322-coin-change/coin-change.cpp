class Solution {
public:
    int f(int i , int amt , vector<int> &coins ,vector<vector<int>> &dp){
        if(i == 0){
           if(amt == 0) return 0;
           if((amt % coins[i]) == 0) return amt / coins[i];
           return 1e6;
        }

        if(dp[i][amt] != -1) return dp[i][amt];

        long long nt = f(i-1 , amt , coins ,dp);
        long long t = 1e6;
        if(amt >= coins[i]){
            t = 1 + f(i , amt - coins[i] , coins ,dp);
        }
        return dp[i][amt] = min(t , nt);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin() ,coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n+1 , vector<int>(amount+1 , -1));
        int ans = f(n-1 , amount ,coins ,dp);
        if(ans == 1e6) return -1;
        return ans;
    }
};
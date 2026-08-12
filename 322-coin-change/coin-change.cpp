class Solution {
public:
    int f(int i, vector<int>& arr, int k , vector<vector<int>> &dp) {
        if (i == 0) {
            if (k % arr[i] == 0)
                return k / arr[i];
            return 1e5;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int nt = f(i - 1, arr, k , dp);
        int take = 1e5;
        if (arr[i] <= k) {
            take = 1 + f(i, arr, k - arr[i] , dp);
        }
        return dp[i][k] = min(take , nt);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1 , -1));
        int ans = f(n - 1, coins, amount , dp);
        if(ans == 1e5) return -1;
        else return ans;
    }
};
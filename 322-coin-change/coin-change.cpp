class Solution {
// private:
//     int f(int i, vector<int>& arr, int k, vector<vector<int>>& dp) {
//         if (i == 0) {
//             if (k % arr[i] == 0)
//                 return k / arr[i];
//             else
//                 return 1e9;
//         }

//         if (dp[i][k] != -1)
//             return dp[i][k];
//         int notTake = f(i - 1, arr, k, dp);

//         int take = 1e9;
//         if (arr[i] <= k) {
//             take = 1 + f(i, arr, k - arr[i], dp);
//         }
//         return dp[i][k] = min(take, notTake);
//     }

public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        for (int k = 0; k <= amount; k++) {
            if (k % coins[0] == 0) {
                dp[0][k] = k / coins[0];
            }
            else{
                dp[0][k] = 1e9;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int k = 0; k <= amount; k++) {
                int notTake = dp[i-1][k];

                int take = 1e9;
                if (coins[i] <= k) {
                    take = 1 + dp[i][k-coins[i]];
                }
                dp[i][k] = min(take, notTake);
            }
        }

        int ans = dp[n-1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};
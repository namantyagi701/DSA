class Solution {
public:
    // int f(int i, int k, vector<int>& arr, vector<vector<int>>& dp) {
    //     if (i == 0) {
    //         if (k == 0)
    //             return 0;
    //         if ((k % arr[i]) == 0) {
    //             return k / arr[i];
    //         }
    //         return 1e7;
    //     }

    //     if (dp[i][k] != -1)
    //         return dp[i][k];

    //     int nt = f(i - 1, k, arr, dp);
    //     int t = 1e7;
    //     if (k >= arr[i]) {
    //         t = 1 + f(i, k - arr[i], arr, dp);
    //     }
    //     return dp[i][k] = min(t, nt);
    // }
    int coinChange(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        for (int j = 0; j <= k; j++) {
            if ((j % arr[0]) == 0) {
                dp[0][j] = (j / arr[0]);
            } else
                dp[0][j] = 1e7;
        }

        for (int i = 1; i < n; i++) {
            for (int kk = 0; kk <= k; kk++) {
                int nt = dp[i-1][kk];
                int t = 1e7;
                if (kk >= arr[i]) {
                    t = 1 + dp[i][kk-arr[i]];
                }
                dp[i][kk] = min(t, nt);
            }
        }

        int ans = dp[n-1][k];

        if (ans == 1e7)
            return -1;

        return ans;
    }
};
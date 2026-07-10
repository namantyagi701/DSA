class Solution {
public:
    int f(int i, vector<int>& arr, int k , vector<int> &dp) {
        if (i == arr.size())
            return 0;
        
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        int maxi = 0;

        for (int x = i; x < arr.size() && x < i + k; x++) {
            maxi = max(maxi, arr[x]);
            int len = x - i + 1;
            ans = max(ans, maxi * len + f(x + 1, arr, k, dp));
        }

        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, arr , k , dp);
    }
};
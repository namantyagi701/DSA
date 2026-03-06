class Solution {
public:
    int f(int i, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (i == prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy) {
            profit = max(-prices[i] + f(i + 1, 0, prices, dp),
                         0 + f(i + 1, 1, prices, dp));
        } else {
            profit = max(prices[i] + f(i + 1, 1, prices, dp),
                         0 + f(i + 1, 0, prices, dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int>curr(2 , 0) , next(2,0);
        int profit = 0;
        next[1] = 0;
        next[0] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for(int j = 0 ; j <= 1 ; j++){
            if (j) {
                curr[j] = max(-prices[i] + next[0],
                             0 + next[1]);
            } else {
                curr[j] = max(prices[i] + next[1],
                             0 + next[0]);
            }
            }
            next = curr;
        }
        return next[1];
    }
};
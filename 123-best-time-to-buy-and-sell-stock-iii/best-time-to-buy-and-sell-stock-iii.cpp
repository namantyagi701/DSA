class Solution {
// private:
//     int f(int i, int buy, int cap, vector<int>& prices,
//           vector<vector<vector<int>>>& dp) {
//         if (cap == 0)
//             return 0;
//         if (i == prices.size())
//             return 0;

//         if (dp[i][buy][cap] != -1)
//             return dp[i][buy][cap];
//         if (buy) {
//             return dp[i][buy][cap] =
//                        max(-prices[i] + f(i + 1, 0, cap, prices, dp),
//                            0 + f(i + 1, 1, cap, prices, dp));
//         } else {
//             return dp[i][buy][cap] =
//                        max(prices[i] + f(i + 1, 1, cap - 1, prices, dp),
//                            0 + f(i + 1, 0, cap, prices, dp));
//         }
//     }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(
        //     n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        vector<vector<int>> curr(2, vector<int>(3, 0)) , next(2, vector<int>(3, 0));
        for (int i = n - 1 ; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int cap = 1; cap < 3; cap++) {
    
                    if (buy) {
                        curr[buy][cap] = max(
                                   -prices[i] + next[0][cap],
                                   0 + next[1][cap]);
                    } else {
                        curr[buy][cap] = max(
                                   prices[i] + next[1][cap-1],
                                   0 + next[0][cap]);
                    }
                }
            }
            next = curr;
        }
        return next[1][2];
    }
};
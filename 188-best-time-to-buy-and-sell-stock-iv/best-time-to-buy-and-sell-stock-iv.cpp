class Solution {
private:
    int f(int i ,int buy , int k , vector<int> &prices , vector<vector<vector<int>>>&dp){
        if(k == 0) return 0;
        if(i == prices.size()) return 0;
        
        if(dp[i][k][buy] != -1) return dp[i][k][buy];
        int profit = 0;
        if(buy){
           profit = max(-prices[i] + f(i+ 1 , 0 , k , prices ,dp),
                          f(i+1 , 1 , k , prices ,dp)); 
        }
        else{
            profit = max(prices[i] + f(i+1 , 1 , k - 1 , prices ,dp),
                          f(i+1 , 0 , k , prices ,dp));
        }
        return dp[i][k][buy] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int i = 0;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n ,vector<vector<int>>(k+1  , vector<int>(2 , -1)));
        return f(i , 1 , k , prices ,dp);
    }
};
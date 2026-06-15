class Solution {
public:
    int f(int i, vector<int> &prices , bool fl , vector<vector<int>> &dp , int fee){
        if(i >= prices.size()) return 0;
        if(dp[i][fl] != -1) return dp[i][fl];
        int nt = f(i + 1 , prices , fl , dp,fee);
        int take = 0;
        if(!fl){
            take = -prices[i] + f(i+1 , prices , true ,dp,fee);
        } 
        else{
            take = prices[i] - fee + f(i+1 , prices , false, dp,fee);
        }
        return dp[i][fl] = max(take, nt);
    }
    int maxProfit(vector<int>& prices , int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2 , -1));
        return f(0 , prices , false , dp ,fee);
    }
};
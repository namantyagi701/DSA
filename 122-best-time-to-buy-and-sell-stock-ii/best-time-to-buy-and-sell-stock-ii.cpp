class Solution {
public:
    int f(int i , bool flag , vector<int> & prices , vector<vector<int>> &dp){
        if(i == prices.size()) return 0;
        
        if(dp[i][flag] != -1) return dp[i][flag];
        int nt = f(i+1, flag , prices, dp);
        int take = 0;
        if(flag){
          take = -prices[i] + f( i + 1 , false , prices,dp);  
        } 
        else{
          take = prices[i] + f(i +1 , true , prices,dp);
        }   
        return dp[i][flag] = max(take , nt);    
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2 , -1));
        return f(0 , true , prices , dp);
    }
};
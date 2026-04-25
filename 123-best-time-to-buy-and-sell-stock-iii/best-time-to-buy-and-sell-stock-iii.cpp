class Solution {
public:
    int f(int i , bool flag , vector<int> & prices , vector<vector<vector<int>>>&dp , int cnt){
        if(i == prices.size()) return 0;
        if(cnt == 0) return 0;
        if(dp[i][flag][cnt] != -1) return dp[i][flag][cnt];
        int take = 0;
        if(flag){
          take = max(-prices[i] + f( i + 1 , false , prices,dp, cnt) , 
                                  f(i + 1 , true , prices , dp ,cnt));  
        } 
        else{
         take = max(prices[i] +f( i + 1 , true , prices,dp, cnt-1) , 
                                  f(i + 1 , false , prices , dp ,cnt));  
        }   
        return dp[i][flag][cnt] = take;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3 , -1)));
        
        return f(0 , true , prices , dp , 2);
    }
};
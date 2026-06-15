class Solution {
public:
    int f(int i , int k , vector<int>&arr , bool fl ,vector<vector<vector<int>>> &dp){
        if(i >= arr.size() || k < 1) return false;
        
        if(dp[i][k][fl] != -1) return dp[i][k][fl];
        
        int nt = f(i+1 , k , arr , fl,dp);
        int t = 0;
        if(!fl){
            t = -arr[i] + f(i+1 , k , arr , true,dp);
        }
        else{
            t = arr[i] + f(i+1 , k-1 , arr , false , dp);
        }
        return dp[i][k][fl] = max(t , nt);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(3 , vector<int>(2 , -1)));
        return f(0 , 2 , prices , false , dp);
    }
};
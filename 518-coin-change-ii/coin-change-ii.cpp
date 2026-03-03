class Solution {
private:
    int f(int i , int k , vector<int> & arr , vector<vector<int>> &dp ){
        if(i == 0){
            if(k % arr[0] == 0) return 1;
            return 0;
        }

        if(dp[i][k] != -1) return dp[i][k];
        int notTake = f(i-1 , k , arr ,dp);
        int take = 0;
        if(arr[i] <= k){
            take = f(i , k - arr[i] , arr ,dp);
        }
        return dp[i][k] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n , vector<int>(amount + 1 , -1));
        return f(n-1 , amount , coins , dp);
    }
};
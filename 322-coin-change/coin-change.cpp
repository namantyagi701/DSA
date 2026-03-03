class Solution {
private:
    int f(int i ,vector<int>& arr , int k , vector<vector<int>> &dp){
        if(i == 0){
            if(k % arr[i] == 0) return k/arr[i]; 
            else return 1e9;
        }

        if(dp[i][k] != -1) return dp[i][k];
        int notTake = f(i-1 , arr , k , dp);

        int take = 1e9;
        if(arr[i] <= k){
            take = 1 +  f(i , arr , k - arr[i] , dp);
        }
        return dp[i][k] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        sort(coins.begin() , coins.end());
        int n = coins.size();
        vector<vector<int>>dp(n , vector<int>(amount + 1 , -1));
        int ans = f(n-1 , coins , amount , dp);
        return ans >= 1e9 ? -1 : ans;
    }
};
class Solution {
public:
    int f(int i , int j , vector<int> &arr , vector<vector<int>> &dp){
        if(i == j) return 0;
        int mini = 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i ; k < j ; k++){
            int curr = (arr[j] - arr[i-1]) + f(i , k , arr ,dp) + f(k+1  , j , arr,dp);
            mini = min(mini , curr);
        } 
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int size = cuts.size();
        vector<vector<int>>dp(size , vector<int>(size , -1));
        return f(1 , size - 1 , cuts ,dp);
    }
};
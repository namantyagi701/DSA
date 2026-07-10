class Solution {
public:
    int f(int i , int j , vector<int> &arr , vector<vector<int>>&dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i ; k <= j ; k++){
            int ans = arr[j+1] - arr[i-1] + f(i , k-1 , arr ,dp) + f(k+1 , j , arr ,dp);

            mini = min(mini ,ans);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin() , 0);
        sort(cuts.begin() , cuts.end());
        int s = cuts.size();
        vector<vector<int>> dp(s+1 , vector<int>(s+1 , -1));
        return f(1 , s-2 , cuts , dp);
    }
};
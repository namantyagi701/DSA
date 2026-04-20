class Solution {
public:
    int f(int i, bool flag, vector<int>& arr, vector<vector<int>>& dp){
        if(i >= arr.size()) return 0;

        if(dp[i][flag] != -1) return dp[i][flag];

        int take = 0;

        if(flag){
            if(arr[i-1] < arr[i]) 
                take = 1 + f(i + 1, !flag, arr, dp);
            else 
                return dp[i][flag] = 0;
        }
        else{
            if(arr[i-1] > arr[i]) 
                take = 1 + f(i + 1, !flag, arr, dp);
            else 
                return dp[i][flag] = 0;
        }

        return dp[i][flag] = take;
    }

    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        int maxi = 0;

        for(int i = 1; i < n; i++){
            int ans1 = f(i, true, arr, dp);
            int ans2 = f(i, false, arr, dp);

            maxi = max(maxi, max(ans1, ans2));
        }

        return 1 + maxi;
    }
};
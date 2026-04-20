class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1;

        vector<vector<int>> dp(n, vector<int>(2,0));
        int maxi = 1;

        for(int i = 1; i < n; i++){

            if(arr[i] > arr[i-1]){
                dp[i][1] = dp[i-1][0] + 1;
                dp[i][0] = 0;
            }
            else if(arr[i] < arr[i-1]){
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = 0;
            }
            else{
                dp[i][0] = dp[i][1] = 0;   
            }

            maxi = max(maxi, max(dp[i][0], dp[i][1]) + 1);
        }

        return maxi;
    }
};
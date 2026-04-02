class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {

        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n+1,
            vector<vector<int>>(m+1, vector<int>(3, -1e9)));

        for(int k=0;k<=2;k++){
            if(coins[0][0] < 0 && k>0)
                dp[1][1][k] = 0;
            else
                dp[1][1][k] = coins[0][0];
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(i==1 && j==1) continue;

                for(int k=0;k<=2;k++){

                    int val = coins[i-1][j-1];

                    // from left
                    dp[i][j][k] = max(dp[i][j][k],
                        dp[i][j-1][k] + val);

                    // from up
                    dp[i][j][k] = max(dp[i][j][k],
                        dp[i-1][j][k] + val);

                    // neutralize robber
                    if(val < 0 && k > 0){
                        dp[i][j][k] = max(dp[i][j][k],
                            dp[i][j-1][k-1]);

                        dp[i][j][k] = max(dp[i][j][k],
                            dp[i-1][j][k-1]);
                    }
                }
            }
        }

        return max({dp[n][m][0], dp[n][m][1], dp[n][m][2]});
    }
};
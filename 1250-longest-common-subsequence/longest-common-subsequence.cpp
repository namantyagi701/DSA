class Solution {
public:
    // int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
    //     if (i == 0 || j == 0)
    //         return 0;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int match = 0;

    //     if (s1[i - 1] == s2[j - 1]) {
    //         match = 1 + f(i - 1, j - 1, s1, s2, dp);
    //     } else {
    //         match = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    //     }
    //     return dp[i][j] = match;
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int match = 0;

                if (text1[i - 1] == text2[j - 1]) {
                    match = 1 + dp[i-1][j-1];
                } else {
                    match =
                        max(dp[i-1][j], dp[i][j-1]);
                }
                dp[i][j] = match;
            }
        }
        return dp[n][m];
    }
};
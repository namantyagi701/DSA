class Solution {
// private:
//     bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
//         if (i == 0 && j == 0)
//             return true;
//         if (j == 0 && i >= 1)
//             return false;

//         if (i == 0 && j >= 1) {
//             for (int k = 0; k < j; k++) {
//                 if (p[k] != '*')
//                     return false;
//             }
//             return true;
//         }
//         if (i == 0)
//             return false;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
//             return dp[i][j] = f(i - 1, j - 1, s, p, dp);
//         if (p[j - 1] == '*')
//             return dp[i][j] = f(i, j - 1, s, p, dp) || f(i - 1, j, s, p, dp);
//         return false;
//     }

public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-1];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                else
                    dp[i][j] = false;
            }
        }
       return dp[n][m];
    }
};
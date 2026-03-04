class Solution {
private:
    // int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
    //     if (i == 0 || j == 0)
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int match = 0;
    //     if (s1[i - 1] == s2[j - 1]) {
    //         match = 1 + f(i - 1, j - 1, s1, s2, dp);
    //     } else {
    //         match = max(f(i, j - 1, s1, s2, dp), f(i - 1, j, s1, s2, dp));
    //     }
    //     return dp[i][j] = match;
    // }

public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int>prev(m+1 , 0) , curr(m+1 , 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                int match = 0;
                if (s1[i - 1] == s2[j - 1]) {
                    match = 1 +prev[j-1];
                } else {
                    match = max(curr[j-1], prev[j]);
                }
                curr[j] = match;
            }
            prev = curr;
        }
        return prev[m];
    }
};
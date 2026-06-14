class Solution {
public:
    int f(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 0;
        if(i == 0) return 0;
        if(j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int match = INT_MIN;
        int notmatch = INT_MIN;
        if(s1[i-1] == s2[j-1]){
            match = 1 + f(i-1 , j-1 , s1 ,s2,dp);
        }
        else{
            notmatch = max(f(i-1 , j , s1 , s2,dp) , f(i , j-1 , s1 , s2 ,dp));
        }
        return dp[i][j] = max(match , notmatch);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        int ans = f(n , m , text1 , text2,dp);
        if(ans < 0) return 0;
        return ans;
    }
};
class Solution {
public:
    bool f(int i , int j , string &s , string &p , vector<vector<int>> &dp){
        if(i == 0 && j == 0) return true;
        if(i == 0){
            while(j > 0 && p[j-1] == '*'){
                j--;
            }
            if( j==0) return true;
            return false;
        }
        if(j == 0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == p [j-1] || p[j-1] == '?'){
            return dp[i][j] = f(i-1 , j-1 , s , p , dp);
        }
        else if(p[j-1] == '*') {
            return dp[i][j] = f(i , j-1 , s , p , dp) || f(i-1 , j , s , p,dp) || f(i-1 , j-1,s , p,dp);
        }
        else{
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        if(n == 0 && m == 0) return true;

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));

        return f(n , m , s , p , dp);
    }
};
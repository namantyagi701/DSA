class Solution {
private:
    int f(int i , int j , string &s , string &t ,  vector<vector<int>> &dp){
        if(i==0 || j == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i-1] == t[j-1]){
            return dp[i][j] =  1 + f(i -1 , j-1 , s ,t ,dp);
        }
        return dp[i][j] = max(f(i , j-1 , s ,t ,dp) , f(i-1 , j , s , t, dp));
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(s.begin() , s.end());
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        return n - f(n , n , s , t , dp);
    }
};
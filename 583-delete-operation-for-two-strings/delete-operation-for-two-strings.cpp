class Solution {
private:
    int f(int i , int j , string word1 , string word2, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return 1 + f(i-1 , j-1 , word1, word2 , dp);
        else{
            return dp[i][j] = max(f(i-1 , j , word1 , word2 , dp) , f(i , j-1 , word1 , word2 , dp));
        }
    }
public:
    int minDistance(string word1, string word2) {
       int i = word1.size();
       int j = word2.size();
       int total = i+j;

       vector<vector<int>> dp(i , vector<int>(j , -1));
       int ans = f(i-1 , j-1 , word1 , word2,dp);
       return total - 2*ans;       
    }
};
class Solution {
public:
    int f(int i , int j , string &s , vector<vector<int>>&dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i ; k <= j ; k++){
            if(isPalindrome(i , k , s)){
                int cost = 1 + f(k + 1 , j  , s , dp);
                mini = min(cost , mini);
            }
        }
        return dp[i][j] = mini;
    }
    
    bool isPalindrome(int i , int j , string &s){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return f(0 , n -1 , s , dp) -1;
    }
};
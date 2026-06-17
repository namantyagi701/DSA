class Solution {
public:
    int isPalindrome(int i , int j , string &s){
        if(i >= s.size() || j >= s.size()) return 0;
        if(i == j) return 1;
        while(i <= j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }

    int f(int i ,int j , string &s , vector<vector<int>> &dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;
        for(int k = j ; k >= i ; k--){
            int curr = 0;
            if(isPalindrome(i , k , s)){
                curr = 1 + f(k+1 , j , s , dp);
                mini = min(mini , curr);
            }
        }
        return dp[i][j] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        if(n == 1) return 0;
        vector<vector<int>>dp(n , vector<int>(n , -1));
        return f(0 , n-1 , s , dp) -1;
    }
};
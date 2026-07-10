class Solution {
public:
    bool isPalindrome(int i , int j , string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int f(int i , string &s, vector<int> &dp){
        if(i==s.size()) return 0;
        
        if(dp[i]!= -1) return dp[i];
        int mini = 1e5;
        int ans = 0;
        for(int k = s.size()-1 ; k >= i ; k--){
            if (isPalindrome(i , k , s)){
                int ans = 1 + f(k+1 ,s,dp); 
                mini = min(mini ,ans);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n , -1);
        return f(0 , s,dp) -1;
    }
};
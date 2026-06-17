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

    int f(int i ,  string &s , vector<int> &dp){
        if(i >= s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int mini = 1e9;
        for(int k = s.size()-1 ; k >= i ; k--){
            int curr = 0;
            if(isPalindrome(i , k , s)){
                curr = 1 + f(k+1, s , dp);
                mini = min(mini , curr);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        // if(n == 1) return 0;
        vector<int> dp(n+1 , -1);
        return f(0 ,s , dp) -1;
    }
};
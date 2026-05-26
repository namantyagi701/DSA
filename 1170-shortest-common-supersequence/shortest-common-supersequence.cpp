class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        string s = "";
        int i = n;
        int j = m;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                s += str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] >= dp[i][j-1]){
                    s += str1[i-1];
                    i--;
                }
                else if(dp[i][j-1] >= dp[i-1][j]) {
                    s += str2[j-1];
                    j--;
                }
            }
        }
        
        if(i == 0){
           while(j > 0){
             s += str2[j-1];
             j--;
           }
        }
        else if(j == 0){
           while(i > 0){
             s += str1[i-1];
             i--;
           }
        }
        reverse(s.begin() , s.end());
        return s;
    }
};
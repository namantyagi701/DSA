class Solution {
public:
    long long f(int i , int j ,vector<int>& a, vector<int>& b , vector<vector<long long>> &dp){
       if(i == a.size()) return 0;
       if(j == b.size()) return LLONG_MIN;
       if(dp[i][j] != -1) return dp[i][j];

       long long next = f(i + 1 , j + 1 , a , b , dp);
       long long take = LLONG_MIN;
       if(next != LLONG_MIN)
       take = (long long) a[i] * (long long)b[j] + next;
       long long notTake = f(i , j + 1 , a , b ,dp);

       return dp[i][j] = max(take , notTake); 
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int i = 0;
        int j = 0;
        int n = a.size();
        int m = b.size();
        vector<vector<long long>>dp(n , vector<long long>(m , -1));
        return f(i , j , a , b , dp);
    }
};
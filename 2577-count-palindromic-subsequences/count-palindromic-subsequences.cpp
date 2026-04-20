class Solution {
public:
    const int MOD = 1e9+7;

    long long dp[10001][6][11][11];

    long long solve(int i, int stage, int a, int b, string &s){
        if(stage == 5) return 1;
        if(i == s.size()) return 0;

        if(dp[i][stage][a+1][b+1] != -1)
            return dp[i][stage][a+1][b+1];

        long long ans = 0;

        ans = solve(i+1, stage, a, b, s) % MOD;

        int d = s[i]-'0';

        if(stage == 0){
            ans = (ans + solve(i+1,1,d,b,s))%MOD;
        }
        else if(stage == 1){
            ans = (ans + solve(i+1,2,a,d,s))%MOD;
        }
        else if(stage == 2){
            ans = (ans + solve(i+1,3,a,b,s))%MOD;
        }
        else if(stage == 3){
            if(d == b)
                ans = (ans + solve(i+1,4,a,b,s))%MOD;
        }
        else if(stage == 4){
            if(d == a)
                ans = (ans + solve(i+1,5,a,b,s))%MOD;
        }

        return dp[i][stage][a+1][b+1] = ans%MOD;
    }

    int countPalindromes(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,-1,-1,s);
    }
};
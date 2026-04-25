class Solution {
public:
    bool f(string& s1 , string& s2) { //s1 - small , s2 -> large
       if(s2.size() != 1+ s1.size()) return false;
       int i = 0 , j = 0;
       while(j < s2.size()){
        if(i < s1.size() && s1[i] == s2[j]){
            i++;   
            j++;
        }
        else{
            j++;
        }
       }
       return i == s1.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        int maxi = 1;
        vector<int> dp(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = n - 1; prev > i; prev--) {
                if (f(words[i], words[prev])) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
class Solution {
public:
    bool f(int idx , string &s , unordered_set<string> &st, vector<int> &dp){
        if(idx == s.size()) return true;
        if(dp[idx] != -1) return dp[idx];
        string curr = "";
        for(int i = idx ; i < s.size() ; i++){
            curr += s[i];
            if(st.find(curr) != st.end()){
                if(f(i+1 , s , st,dp)) return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        int n = s.size();
        for(int i = 0 ; i < wordDict.size() ; i++){
            st.insert(wordDict[i]);
        }
        vector<int>dp(n , -1);
        return f(0 , s, st ,dp);
    }
};
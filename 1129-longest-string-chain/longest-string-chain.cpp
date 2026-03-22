class Solution {
public:
    unordered_map<string , int >dp;
    unordered_set<string>st;
    
    int solve(string w){
        if(dp.count(w)) return dp[w];

        int maxLen = 1;
        for(int i = 0 ; i < w.size() ; i++){
            string prev = w.substr(0 , i) + w.substr(i + 1);

            if(st.count(prev)){
                maxLen = max(maxLen , 1 + solve(prev));
            }
        }
        return dp[w] = maxLen;
    }
    int longestStrChain(vector<string>& words) {
        for(auto &w : words) st.insert(w);

        int ans = 1;
        for(int i = 0 ; i < words.size() ; i++){
            ans = max(ans , solve(words[i] ));
        }
        return ans;
    }
};
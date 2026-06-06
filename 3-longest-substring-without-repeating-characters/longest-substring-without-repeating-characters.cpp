class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();
        if(n == 0) return 0;
        unordered_set<char> st;
        int maxi = 1;
        while(l < n && r < n){
            while(st.count(s[r])){
              st.erase(s[l]);
              l++;
            }
            st.insert(s[r]);
            maxi = max(maxi , r - l + 1);
            r++;
        }
        return maxi;
    }
};
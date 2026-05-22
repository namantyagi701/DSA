class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        unordered_set<char> st;
        int l = 0;
        int r = 0;
        int maxlen = 1;
        while (l < n && r < n) {
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            r++;
            maxlen = max(r-l, maxlen);
        }
        return maxlen;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        unordered_set<int> st;
        int l = 0;
        int r = 0;
        int len = 0;
        int maxlen = 1;
        while (l < n && r < n) {
            while (st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
                len--;
            }
            st.insert(s[r]);
            r++;
            len++;
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};
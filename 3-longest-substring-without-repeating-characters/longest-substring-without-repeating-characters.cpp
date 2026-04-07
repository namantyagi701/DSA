class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(s.size() == 1) return 1;
        int left = 0;
        int right = 0;
        unordered_set<int>st;
        // int count = 0;
        int ans = 0;
        while(left < n && right < n){
            if(st.find(s[right]) == st.end()){
              st.insert(s[right]);
              ans = max(ans , right - left + 1);
              right++;              
            }
            else{
              st.erase(s[left]);
              left++;
            }
        }
        return ans;
    }
};
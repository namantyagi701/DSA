class Solution {
public:
    int characterReplacement(string s, int t) {
        int ans = 1;
        int n = s.size();
        int k = t;
        for(char ch = 'A' ; ch <= 'Z' ; ch++){
            int l = 0;
            int r = 0;
            k = t;
            while(l < n && r < n){
               if(s[r] != ch) k--;
               while(k < 0){
                if(s[l] != ch) k++;
                l++;
               }
               ans = max(ans , r - l + 1);
               r++;
            }
            if(ans == n) return n;
        }
        return ans;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0;
        int maxLen = 0;
        unordered_map<char , int>freq;
        int r = 0;
        int l = 0;
        int n = s.size();
        while(r < n){
            freq[s[r]]++;
            maxFreq = max(maxFreq , freq[s[r]]);
            while((r - l + 1) - maxFreq > k){
                freq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen , r-l+1);
            r++;
        }
        return maxLen;
    }
};
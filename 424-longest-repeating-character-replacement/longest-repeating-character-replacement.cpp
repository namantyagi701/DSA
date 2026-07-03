class Solution {
public:
    int characterReplacement(string s, int x) {
        int i = 0;
        int j = 0;
        int n = s.size();
        vector<int> freq(26);
        int ans = 0;
        while (i < n && j < n) {
            freq[s[j] - 'A']++;
            int maxFreq = 0;
            for (int k = 0; k < 26; k++) {
                if (freq[k] > maxFreq) {
                    maxFreq = freq[k];
                }
            }
            while (((j - i) + 1) - maxFreq > x) {
                freq[s[i] - 'A']--;
                i++;
                maxFreq = 0;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > maxFreq) {
                        maxFreq = freq[k];
                    }
                }
            }
            ans = max(ans, ((j - i) + 1));
            j++;
        }
        return ans;
    }
};
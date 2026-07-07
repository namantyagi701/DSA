class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        vector<int> freq(26, 0);
        while (i < n && j < n) {
            freq[s[j] - 'A']++;
            int maxi = 0;
            for (int k = 0; k < 26; k++) {
                maxi = max(maxi, freq[k]);
            }
            while (i < n && (j - i + 1) - maxi > k) {
                freq[s[i] - 'A']--;
                i++;
                for (int k = 0; k < 26; k++) {
                    maxi = max(maxi, freq[k]);
                }
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
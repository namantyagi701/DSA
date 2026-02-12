class Solution {
public:
    bool isBalanced(unordered_map<char, int>& freq) {
        int val = 0;
        for (auto& p : freq) {
            if (p.second == 0) continue;
            if (val == 0) val = p.second;
            else if (p.second != val) return false;
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;

            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                if (isBalanced(freq)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};

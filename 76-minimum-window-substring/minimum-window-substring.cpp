class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m)
            return "";
        vector<int> mpp(256, 0);
        ;
        for (auto it : t) {
            mpp[it]++;
        }
        int i = 0;
        int j = 0;
        int cnt = 0;
        int sIdx = -1;
        int len = 1e9;
        while (i < n && j < n) {
            if (mpp[s[j]] > 0) {
                cnt++;
            }
            mpp[s[j]]--;
            if (cnt == m) {
                while (cnt == m) {
                    if (j - i + 1 < len) {
                        len = j - i + 1;
                        sIdx = i;
                    }
                    mpp[s[i]]++;
                    if (mpp[s[i]] > 0) {
                        cnt--;
                    }
                    i++;
                }
            }
            j++;
        }
        if(sIdx == -1) return "";
        return s.substr(sIdx, len);
    }
};
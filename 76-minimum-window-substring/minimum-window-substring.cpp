class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size())
            return "";
        unordered_map<int, int> mpp;
        for (auto it : t) {
            mpp[it]++;
        }
        int l = 0;
        int r = 0;
        int cnt = 0;
        int sIdx = -1;
        int n = s.size();
        int len = INT_MAX;
        while (l < n && r < n) {
            if (!mpp.count(s[r]))
                mpp[s[r]] = -1;
            if (mpp[s[r]] > 0) {
                cnt++;
            }
            mpp[s[r]]--;
            while (l < n && cnt == t.size()) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    sIdx = l;
                }

                mpp[s[l]]++;
                if (mpp[s[l]] > 0)
                    cnt--;
                l++;
            }
            r++;
        }
        if (len == INT_MAX)
            return "";
        return s.substr(sIdx, len);
    }
};
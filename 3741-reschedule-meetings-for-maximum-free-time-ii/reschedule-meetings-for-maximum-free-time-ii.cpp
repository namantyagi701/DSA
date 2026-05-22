class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {

        int n = startTime.size();

        vector<int> gap;

        gap.push_back(startTime[0]);

        for(int i = 1; i < n; i++) {
            gap.push_back(startTime[i] - endTime[i - 1]);
        }

        gap.push_back(eventTime - endTime[n - 1]);

        int m = gap.size();

        vector<int> pref(m), suff(m);

        pref[0] = gap[0];
        for(int i = 1; i < m; i++) {
            pref[i] = max(pref[i - 1], gap[i]);
        }

        suff[m - 1] = gap[m - 1];
        for(int i = m - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], gap[i]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {

            int duration = endTime[i] - startTime[i];

            int merged = gap[i] + gap[i + 1];

            ans = max(ans, merged);

            int leftMax = (i - 1 >= 0) ? pref[i - 1] : 0;
            int rightMax = (i + 2 < m) ? suff[i + 2] : 0;

            int bestGap = max(leftMax, rightMax);

            if(bestGap >= duration) {
                ans = max(ans, merged + duration);
            }
        }

        return ans;
    }
};
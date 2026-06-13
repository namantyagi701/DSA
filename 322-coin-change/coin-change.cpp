class Solution {
public:
    int coinChange(vector<int>& arr, int k) {
        // sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int>curr(k + 1 , 0);
        for (int j = 0; j <= k; j++) {
            if ((j % arr[0]) == 0) {
                curr[j] = (j / arr[0]);
            } else
                curr[j] = 1e7;
        }

        for (int i = 1; i < n; i++) {
            for (int kk = 0; kk <= k; kk++) {
                int nt = curr[kk];
                int t = 1e7;
                if (kk >= arr[i]) {
                    t = 1 + curr[kk-arr[i]];
                }
                curr[kk] = min(t, nt);
            }
        }

        int ans = curr[k];

        if (ans == 1e7)
            return -1;

        return ans;
    }
};
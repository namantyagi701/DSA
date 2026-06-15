class Solution {
public:
    int f(int i, vector<int>& nums, int prev, vector<vector<int>>& dp) {
        int n = nums.size();
        if (i >= n)
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        int nt = f(i + 1, nums, prev, dp);
        int t = 0;
        if (prev == -1 || nums[prev] < nums[i]) {
            t = 1 + f(i + 1, nums, i, dp);
        }
        return dp[i][prev + 1] = max(t, nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>previous(n+1 , 0);
        vector<int>curr(n+1 , 0);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int len = previous[prev + 1];
                int t = 0;
                if (prev == -1 || nums[prev] < nums[i]) {
                    len = max(len ,1 + previous[i + 1]);
                }
                curr[prev + 1] = len;
            }
            previous = curr;
        }
        return curr[0];
    }
};
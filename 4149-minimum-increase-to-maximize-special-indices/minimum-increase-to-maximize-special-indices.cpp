class Solution {
public:
    long long f(int i, bool flag, vector<int>& nums , vector<vector<long long>>&dp) {
        if (i >= nums.size() - 1)
            return 0;
        if(dp[i][1] != -1) return dp[i][1];
        long long res = max(0, max(nums[i - 1], nums[i + 1]) - nums[i] + 1 );

        if (flag) {
            return dp[i][flag] = res + f(i + 2, flag, nums , dp);
        } else {
            dp[i][0] = res + f(i + 2, flag, nums , dp);
            dp[i][1] = res + f(i + 3, true, nums, dp);
            return min(dp[i][0] , dp[i][1]);
        }
    }
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        if (n % 2 == 1) { // odd length
            long long minOp = 0;
            for (int i = 1; i < nums.size() - 1; i += 2) {
                if (nums[i] <= nums[i - 1] || nums[i] <= nums[i + 1]) {
                    int maxi = max(nums[i - 1], nums[i + 1]);
                    minOp += maxi - nums[i] + 1;
                }
            }
            return minOp;
        } else {
            vector<vector<long long>> dp(n-1 , vector<long long>(2  , -1));
            return min(f(1, false, nums  , dp), f(2, true, nums , dp));
        }
    }
};
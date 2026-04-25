class Solution {
public:
    int f(int i , vector<int> &nums , int k , vector<vector<int>> &dp , int offset){
        if (k + offset < 0 || k + offset >= dp[0].size()) return 0;
        if(i == nums.size()-1){
            if(nums[i] == 0 && k == 0) return 2;
            if(k - nums[i] == 0 || k + nums[i]== 0 ) return 1;
            return 0;
        }
        if(i >= nums.size()) return 0;
    
        if(dp[i][k + offset] != -1) return dp[i][k + offset];

        int sub = f(i + 1 , nums , k + nums[i] , dp , offset);

        int add = 0;
        add = f(i + 1 , nums , k - nums[i] , dp , offset);

        return dp[i][k + offset] = sub + add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums) sum += it;
        vector<vector<int>>dp(n , vector<int>(2 * sum + 1 , -1));
        return f(0 , nums , target , dp , sum);
    }
};
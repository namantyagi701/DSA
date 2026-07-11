class Solution {
public:
    int f(int i , vector<int> &nums , int k){
        if(i == 0){
            if(k == 0 && nums[i] == 0) return 2;
            if(-nums[i] == k || nums[i] == k) return 1;
            return 0;
        }
    
        int subs = f(i-1 , nums , k + nums[i]);
        int add = 0;
        add = f(i-1 , nums , k - nums[i]);

        return add + subs;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(n-1 , nums , target);
    }
};
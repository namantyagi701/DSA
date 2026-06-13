class Solution {
public:
    int f(int i , int k , vector<int>& nums){
        if(i == 0){
           if(k == 0 && nums[i] == 0) return 2;
           if(k - nums[i] == 0 || k + nums[i] == 0) return 1;
           return 0;
        }

        int add =  f(i - 1 , k - nums[i] , nums);
        int subs = f(i - 1 , k + nums[i] , nums);

        return add + subs;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(n-1 , target , nums);
    }
};
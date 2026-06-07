class Solution {
public:
    int f(vector<int>& nums , int k){
        if(k < 0) return 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int cnt = 0;
        int sum = 0;
        while(l < n && r < n){
            sum += nums[r];
            while(sum > k){
                sum -= nums[l];
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums , goal) - f(nums , goal -1);
    }
};
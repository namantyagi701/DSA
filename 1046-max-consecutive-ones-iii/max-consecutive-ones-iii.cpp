class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int n = nums.size();
        while(l < n && r < n){
           if(nums[r] == 0) k = k - 1;
           while(k < 0){
             if(nums[l] == 0) k = k + 1;
             l++;
           }
           ans = max(ans , r - l + 1);
           r++;
        }
        return ans;
    }
};
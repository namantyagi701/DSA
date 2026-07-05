class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int n = nums.size();
        int j = 0;
        int ans = 0;
        while(i < n && j < n){
            if(nums[j] == 0) k--;
            while(i < n && k < 0){
                if(nums[i] == 0){
                    k++;
                }
                i++;
            }
            ans = max(ans , j - i + 1);
            j++;
        }
        return ans;
    }
};
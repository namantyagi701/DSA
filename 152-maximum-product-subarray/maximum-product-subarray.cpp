class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        for(int i = 1 ; i < n ; i++){
            int curr = nums[i];
            
            int tmax = max({curr , maxi * curr , mini * curr});
            int tmin = min({curr , maxi *curr , mini * curr});
            
            maxi = tmax;
            mini = tmin;

            ans = max(ans , maxi);
        }
        return ans;
    }
};
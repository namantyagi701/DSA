class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        int maxN = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] < 0) maxN = max(maxN , nums[i]);
            sum += nums[i];
            if(sum < 0) sum = 0;
            else maxi = max(sum , maxi);
        }
        if(maxi == INT_MIN){
           return maxN;
        }
        return maxi;
    }
};
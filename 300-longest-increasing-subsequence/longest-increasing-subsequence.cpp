class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n , 1);
        int maxi = 1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i] && 1 + temp[j] > temp[i]){
                    temp[i] = 1 + temp[j];
                    maxi = max(maxi , temp[i]);
                }
            }
        }
        return maxi;
    }
};
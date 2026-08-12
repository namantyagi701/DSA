class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        long long sum = 0;
        int i = 0;
        int len = 0;
        int n = nums.size();
        for(int j = 0 ; j < n ; j++){
            sum += nums[j];
            while((long long) nums[j] * (j - i + 1) - sum > k){
                sum -= nums[i];
                i++;
            }       
            len = max(len , j - i + 1);     
        }
        return len;
    }
};
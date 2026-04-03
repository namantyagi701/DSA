class Solution {
public:
    int No_of_subarrays(vector<int>& nums, int n, int number) {
        int nos = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] <= number){
                sum += nums[i];
            }
            else{
                nos++;
                sum = nums[i];
            }
        }
        return nos;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = INT_MIN, high = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            high += nums[i];
            low = max(low, nums[i]);
        }
        while (low <= high) {
            int mid = (low + high) / 2;
            int no_of_subarrays = No_of_subarrays(nums, n, mid);
            if(k < no_of_subarrays){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};
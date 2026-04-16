class Solution {
public:
    int lb(vector<int>& arr, int target){
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] >= target){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

    int ub(vector<int>& arr, int target){
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] > target){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1 , -1};
        int f_i = lb(nums , target);
        int l_i = ub(nums , target);
       
        if(f_i == -1 || nums[f_i] != target) return {-1 , -1};
        if(l_i == -1){
            l_i = nums.size()-1;
        }
        else l_i = l_i -1;
        return {f_i , l_i};
    }
};
class Solution {
public:
    int f(int div , vector<int> &arr , int k){
        int sum = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            int x = (arr[i] + div -1)/div; 
            sum += x;
        }
       if(sum > k) return false;
       return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int n = nums.size();
        int high = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            high = max(high , nums[i]);
        }
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(f(mid , nums , threshold)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
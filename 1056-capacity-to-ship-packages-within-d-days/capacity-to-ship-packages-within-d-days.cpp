class Solution {
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int low = *max_element(arr.begin(), arr.end());
        int high = 0;
        int n = arr.size();
        for(int i = 0; i < n ; i++){
           high += arr[i];
        }
        int ans = 0;
        
        while(low <= high){
            int mid = (low + high)/2;
            int count = 1;
            int sum = 0;
            for(int i = 0 ; i < n ; i++){
                if(sum + arr[i] > mid){
                    sum = arr[i];
                    count++;
                }
                else{
                    sum += arr[i];
                }
            }
            if(count <= days){
                high = mid -1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
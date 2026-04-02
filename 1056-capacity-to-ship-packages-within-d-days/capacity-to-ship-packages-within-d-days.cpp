class Solution {
public:
    int shipWithinDays(vector<int>& arr, int days) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin() , arr.end() , 0);
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            int count = 1;
            int sum = 0;
            for(int i = 0 ; i < arr.size() ; i++){
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
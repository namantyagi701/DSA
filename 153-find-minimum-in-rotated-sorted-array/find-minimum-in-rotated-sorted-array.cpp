class Solution {
public:
    int findMin(vector<int>& arr) {
        if(arr.size() == 1) return arr[0];
        int low = 0;
        int n = arr.size();
        int high = n-1;
        if(arr[low] < arr[high]){
            return arr[low];
        }
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(mid == 0 && arr[mid + 1] > arr[mid]) return arr[mid];
            else if(mid == n-1 && arr[mid] < arr[mid -1]) return arr[mid];
            else if(mid != 0 && mid < n-1 && arr[mid + 1] > arr[mid] && arr[mid] < arr[mid -1]) return arr[mid];
            else if(arr[mid] > arr[low]){
                //left sorted
                if(arr[mid] > arr[high]){
                    low = mid + 1;
                }
                else{
                    high = mid -1;
                }
            }
            else{
                //right sorted
                if(arr[mid] < arr[high]){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};
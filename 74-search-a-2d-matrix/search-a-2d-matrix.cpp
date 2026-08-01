class Solution {
public:
    bool bs(vector<int> &arr, int k){
        int low = 0;
        int high = arr.size()-1;
        while(low <=high){
            int mid = (low + high)/2;
            if(arr[mid] == k) return true;
            else if(arr[mid] < k){
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& arr, int k) {
        int low = 0;
        int high = arr.size()-1;
        int j = arr[0].size()-1;
        int idx = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid][j] == k) return true;
            else if(arr[mid][j] > k){
                idx = mid;
                high = mid -1 ;
            }
            else{
                low = mid + 1;
            }
        }
        if(idx == -1)
        return false;

        else{
            return bs(arr[idx] , k);
        }
    }
};
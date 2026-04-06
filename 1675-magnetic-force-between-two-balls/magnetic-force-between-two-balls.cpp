class Solution {
public:
    bool f(int k , vector<int> &arr , int m){
        int cnt = 1;
        int last = arr[0];
        for(int i = 1 ;i < arr.size() ; i++){
            if(abs(arr[i] - last) >= k){
                cnt++;
                last = arr[i];
            }
            if(cnt >= m) return true;
        }
        return false;
    }
    int maxDistance(vector<int>& arr, int m) {
        sort(arr.begin() , arr.end());
        int low = 1;
        int temp = INT_MIN;
        for(int i = 0 ; i < arr.size() ; i++){
            temp = max(temp , arr[i]);
        }
        int ans = 0;
        int high = temp - low;
        while(low <= high){
            int mid = (low + high)/2;

            if(f(mid , arr , m)){
               ans = mid;
               low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};
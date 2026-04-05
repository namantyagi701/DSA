class Solution {
public:
    int f(vector<int> &arr , int p){
        int cnt = 1;
        int sum = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(sum + arr[i] <= p){
                sum += arr[i];
            }
            else{
                cnt++;
                sum = arr[i];
            }
        }
        return cnt;
    }
    
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        int high = accumulate(arr.begin(), arr.end(), 0);
        int low = INT_MIN;
        int ans = 0;
        if (n < k)
            return -1;
        for (int i = 0; i < n; i++) {
            low = max(low, arr[i]);
        }
        while (low <= high) {

            int mid = (low + high) / 2;

            if (k >= f(arr, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
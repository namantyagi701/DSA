class Solution {
public:
    int bloom(vector<int> &arr , int curr , int k){
        int n = arr.size();
        int ans = 0;
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] <= curr){
                cnt++;
                if(cnt == k) {
                    ans++;
                    cnt = 0;
                    }
            } 
            else{
                cnt = 0;
            }
        }
        return ans;
    }

    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        long long temp = 1LL * m *k;
        if(temp > n) return -1;
        int ans = 0;
        int low = 1;
        int high = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            low = min(low , arr[i]);
            high = max(high , arr[i]);
        }
        while(low <= high){
            int mid = (low + high)/2;

            int x = bloom(arr , mid , k);
            if(x >= m){
               ans = mid;
               high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
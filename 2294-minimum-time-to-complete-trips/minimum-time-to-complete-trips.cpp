class Solution {
public:
    bool f(long long curr ,vector<int>& arr , int k){
        long long sum = 0;
        for(int i = 0 ; i < arr.size() ; i++){
                int x = (curr / arr[i]);
                sum += x;
        }
        if(sum >= k) return true;
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1.0;
        long long high = LLONG_MAX;
        for(int i = 0 ; i < time.size() ; i++){
            high = min(high , (long long)time[i]);
        }
        high = high * totalTrips;
        long long ans = 0;
        while(low <= high){
            long long mid = (low + high)/2;
            if(f(mid , time , totalTrips)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
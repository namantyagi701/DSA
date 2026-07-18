class Solution {
public:
    long long f(vector<int>&piles , int k){
        long long sum = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            sum += (piles[i] + k - 1)/k;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int k) {
        int n = piles.size();
        long long maxi = LLONG_MIN;
        long long mini = 1;
        long long ans = -1;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , (long long)piles[i]);
            // mini = min(mini , (long long)piles[i]);
        } 
        long long low = mini;
        long long high = maxi;
        while(low <= high){
            long long mid = (low + high)/2;
            long long curr = f(piles , mid);
            
            if(curr <= k){
              ans = mid;
              high = mid - 1;
            }
            else if(curr > k){
               low = mid + 1;
            }
        }
        return ans;
    }
};
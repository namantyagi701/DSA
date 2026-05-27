class Solution {
public:
    long long calc(vector<int> &piles , int k){
        long long totalh = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            totalh += (piles[i] + k - 1) / k;
        }
        return totalh;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long high;
        long long maxi = piles[0];
        for(int i = 1 ; i < piles.size() ; i++){
              maxi = max(maxi , 1LL *piles[i]);
        }
        long long ans;
        high = maxi;
        long long low = 1;
        while(low <= high){
            long long mid = low +(high-low)/2;

            long long curr = calc(piles , mid);
            if(curr <= h){
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
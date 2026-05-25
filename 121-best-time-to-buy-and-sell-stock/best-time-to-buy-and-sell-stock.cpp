class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>inc(n);
        vector<int>dec(n);
        int maxi = INT_MIN;
        for(int i = n- 1; i >= 0 ; i--){
           if(maxi < prices[i]){
            maxi = prices[i];
           }
           inc[i] = maxi;
        }
        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++){
           if(mini > prices[i]){
            mini = prices[i];
           }
           dec[i] = mini;
        }
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            long long diff = inc[i] - dec[i];
            ans = max(ans , diff);
        }
        return (int)ans;
    }
};
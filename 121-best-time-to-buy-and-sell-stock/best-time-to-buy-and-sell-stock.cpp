class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini = arr[0];
        int minidx = 0;
        int ans = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            if(arr[i] < mini){
                mini = arr[i];
                minidx = i;
            }
            if(minidx < i){
                ans = max(ans , arr[i] - mini);
                cout<<ans;
            }
        }
        return ans;
    }
};
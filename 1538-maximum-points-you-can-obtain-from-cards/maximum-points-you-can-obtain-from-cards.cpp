class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum = 0;
        int n = arr.size();
        for(int i = 0 ; i <n ; i++){
           sum += arr[i];
        }
        int rem = n - k;
        int l = 0;
        int r = 0;
        int mini = sum;
        int s = 0;
        while(l < n && r < n){
            if(r - l + 1 > rem){
                mini = min(mini , s);
                s -= arr[l];
                l++;
            }
            s += arr[r];
            r++;
        }
        mini = min(mini , s);
        return sum - mini;        
    }
};
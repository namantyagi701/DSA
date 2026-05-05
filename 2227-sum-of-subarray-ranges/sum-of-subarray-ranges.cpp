class Solution {
public:
    long long subArrayRanges(vector<int>& arr) {
        int mini;
        int maxi;
        long long sum = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            mini = arr[i];
            maxi = arr[i];
            for(int j = i ; j < arr.size() ; j++){
                mini = min(mini , arr[j]);
                maxi = max(maxi , arr[j]);
                sum += (maxi - mini);
            }
        }
        return sum;
    }
};
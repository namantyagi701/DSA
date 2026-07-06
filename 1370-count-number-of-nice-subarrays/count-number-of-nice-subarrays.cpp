class Solution {
public:
    int f(vector<int>& arr , int k){
        int i = 0;
        int j = 0;
        int n = arr.size();
        int sum = 0;
        long long cnt = 0;
        while(i < n && j < n){
            sum += arr[j];
            while(sum > k){
                sum -= arr[i];
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(n);
        for(int i = 0 ; i < n ; i++){
            if(nums[i] % 2 == 0) arr[i] = 0;
            else arr[i] = 1;
        }
        return f(arr , k) - f(arr , k-1);
    }
};
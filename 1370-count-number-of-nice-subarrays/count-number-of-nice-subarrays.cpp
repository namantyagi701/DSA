class Solution {
public:
    int f(vector<int>& arr , int k){
        // if(k < 0) return 0;
        int l = 0;
        int r = 0;
        int cnt = 0;
        int sum = 0;
        int n = arr.size();
        while(l < n && r < n){
            if(arr[r] % 2 == 1) k--;
            while(k < 0){
                if(arr[l] % 2 == 1) k++;
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums , k) - f(nums , k -1);
    }
};
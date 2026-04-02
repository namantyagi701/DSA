class Solution {
public:
    int f(int low , int high , vector<int> &arr , int k){
        if(low > high) return -1;
        int mid = (low + high)/2;
        if(arr[mid] == k) return mid;
        else if(arr[mid] < k) return f(mid + 1 , high , arr , k);
        else return f(low , mid -1 , arr , k);
    }
    int search(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        return f(0 , n-1 , nums , target);
    }
};
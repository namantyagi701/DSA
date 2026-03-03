class Solution {
private:
    int f(int i  , int k , vector<int>& arr){
       
        if(i == 0){
            if(k == 0 && arr[0] == 0) return 2;
            if(k == arr[i] || -k == arr[i]) return 1;
            return 0;
        }

        int add = f(i-1 , k - arr[i] , arr);
        int sub = f(i-1 , k + arr[i], arr);

        return add + sub; 
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(n-1 ,target , nums);
    }
};
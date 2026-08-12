class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        if(k == 0) return 0;
        int len = 0;
        unordered_map<int,int>mpp;
        while(i < n && j < n ){
            mpp[nums[j]]++;
            while(mpp[nums[j]] > k){
                mpp[nums[i]]--;
                i++;
            }
            len = max(len , j - i + 1);
            j++;
        }
        return len;
    }
};
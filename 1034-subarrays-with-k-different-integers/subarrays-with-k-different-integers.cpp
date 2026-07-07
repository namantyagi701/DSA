class Solution {
public:
    int f(vector<int> &nums , int k){
        int i = 0;
        int j = 0;
        int n = nums.size();
        unordered_map<int,int>mpp;
        int tot = 0;
        while(i < n && j < n){
            mpp[nums[j]]++;
            while(mpp.size() > k){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }
            tot += (j - i + 1);
            j++;
        }
        return tot;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums , k) - f(nums , k -1);
    }
};
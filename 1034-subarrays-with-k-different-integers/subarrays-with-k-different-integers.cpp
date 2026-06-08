class Solution {
public:
    int f(vector<int> &nums , int k){
        unordered_map<int , int>mpp;
        // if(k < 0) return 0;
        int l = 0;
        int r = 0;
        int cnt = 0;
        int n = nums.size();
        while(l < n && r < n){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt += (r - l +1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums , k) - f(nums , k-1);
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        int l = 0;
        int ps = 0;
        int cnt = 0;
        while(l < nums.size()){
            ps += nums[l];
            int rem = ps - k;
            cnt += mpp[rem];
            mpp[ps]++;
            l++;
        }
        return cnt;
    }
};
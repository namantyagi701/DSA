class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        int pref = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            pref += nums[i];
            int rem = pref - k;
            ans += mpp[rem];
            mpp[pref]++;
        }
        return ans;
    }
};
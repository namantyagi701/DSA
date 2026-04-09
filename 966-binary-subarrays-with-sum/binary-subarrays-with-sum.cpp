class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int pref = 0;
        unordered_map<int, int> mpp;
        mpp[0]++;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i];
            int rem = pref - goal;
            cnt += mpp[rem];
            mpp[pref]++;
        }
        return cnt;
    }
};
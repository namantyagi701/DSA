class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int>mpp;
        for(int i = 0 ; i < nums.size() ; i++){
            // if(nums[i] > target) continue;
            int rem = target - nums[i];
            if(mpp.find(rem) != mpp.end()){
               int idx = mpp[rem];
               return {idx,i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};
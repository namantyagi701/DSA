class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int maxi = INT_MIN;
        while(i < n && j < n){
            mpp[nums[j]]++;
            while(mpp.size() > 2 && i < n){
                mpp[nums[i]]--;
                if(mpp[nums[i]] == 0) mpp.erase(nums[i]);
                i++;
            }
            maxi = max(maxi , j - i + 1);
            j++;
        }
        return maxi;
    }
};
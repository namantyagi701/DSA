class Solution {
public:
    int atmost(vector<int> & nums , int k){
        int count = 0;
        int curr = 0;
        int l = 0;
        for(int r = 0 ; r < nums.size() ; r++){
            if(nums[r] % 2) curr++;

            while(curr > k){
                if(nums[l] % 2) curr--;
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums , k) - atmost(nums , k -1);
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int target = n / 3;
        int ele = nums[0];
        vector<int> ans;
        int i = 0;
        while(i < n){
            int cnt = 0;
            while(i < n && nums[i] == ele){
                cnt++;
                i++;
            }
            if(cnt > target){
                ans.push_back(ele);
            }
            if(i < n)
            ele = nums[i];
        }
        return ans;
    }
};
class Solution {
public:
    void f(int i , vector<int>temp, vector<int> &nums, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }

        f(i +  1 , temp , nums , ans);
                
        temp.push_back(nums[i]);
        f(i + 1 , temp , nums , ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0 , temp, nums , ans);
        return ans;
    }
};
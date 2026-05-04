class Solution {
public:
    void f(int i , int k , vector<vector<int>>&ans, vector<int>&ds , vector<int>&arr){
        if(i >= arr.size()){
            if(k == 0){
                ans.push_back(ds);
            }
                return;
        }

        if(arr[i] <= k){
            ds.push_back(arr[i]);
            f(i , k-arr[i] , ans , ds , arr);
            ds.pop_back();
        }
        f(i + 1  , k , ans , ds ,arr);
  
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0 , target , ans , ds , candidates);
        return ans;
    }
};
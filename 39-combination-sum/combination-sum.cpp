class Solution {
public:
    void f(int i , int k , vector<int> &arr , vector<vector<int>>&ans , vector<int> &temp){
        if(k == 0){
           ans.push_back(temp);
           return;
        }
        if(i < 0) {
            return;
        }

        f(i - 1 , k , arr ,ans , temp);
        if(arr[i] <= k){
            temp.push_back(arr[i]);
            f(i , k - arr[i] , arr , ans , temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = candidates.size();
        f(n-1 , target , candidates , ans , temp);
        return ans;
    }
};
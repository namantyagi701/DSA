class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        int i = 0;
        vector<vector<int>>ans;
        while(i < n){
            int mini = arr[i][0];
            int maxi = arr[i][1];
            i++;
            while(i < n && arr[i][0] <= maxi){
                mini = min(arr[i][0] ,mini);
                maxi = max(arr[i][1] ,maxi);
                i++;
            }
            ans.push_back({mini , maxi});
        }
        return ans;
    }
};
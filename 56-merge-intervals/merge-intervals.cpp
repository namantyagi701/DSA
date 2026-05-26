class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        int i = 0;
        vector<vector<int>>ans;
        while(i < n){
            int first = arr[i][0];
            int second = arr[i][1];
            i++;
            int mini = first;
            int maxi = second;
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
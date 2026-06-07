class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int,int>mpp;
        int l = 0;
        int r = 0;
        int n = arr.size();
        // unordered_map<int,int>mpp;
        int ans = 0;
        while(l < n && r < n){
            mpp[arr[r]]++;
            while(mpp.size() > 2){
              mpp[arr[l]]--;
              if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
              l++;
            }
            ans = max(ans , r - l + 1);
            r++;
        }
        return ans;
    }
};
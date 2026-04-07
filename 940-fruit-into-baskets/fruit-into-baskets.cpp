class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int l = 0;
        int r = 0;
        int maxi = 0;
        int n = arr.size();
        unordered_map<int , int> mpp;
        while(r < n){
            mpp[arr[r]]++;
            while(mpp.size() > 2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
                l++;
            }
            maxi = max(maxi , r - l + 1);
            r++;
        }
        return maxi;
    }
};
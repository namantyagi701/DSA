class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>mpp;
        int l = 0;
        int r = 0;
        int n = fruits.size();
        int maxLen = 0;
        while(l < n && r < n){
            mpp[fruits[r]]++;
            while(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                l++;
            }
            maxLen = max(r - l + 1 , maxLen);
            r++;
        }
        return maxLen;
    }
};
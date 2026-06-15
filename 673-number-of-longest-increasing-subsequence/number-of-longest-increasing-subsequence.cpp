class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n , 1);
        vector<int>cnt(n , 1);
        int maxi = INT_MIN;
        // int idx = -1;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i]){
                    if(temp[i] < 1 + temp[j]){
                        temp[i] = 1 + temp[j];
                        cnt[i] = cnt[j];
                    }
                    else if(temp[i] == 1 + temp[j]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            if(temp[i] > maxi){
                maxi = temp[i];
            }
        }
        int count = 0;
            for(int i = 0 ; i < n ; i++){
                if(temp[i] == maxi){
                    count += cnt[i];
                }
            }
        return count;
    }
};
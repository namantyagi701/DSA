class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        vector<int>dp(n ,1);
        vector<int>hash(n);

        int idx = 0;
        int maxi = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            hash[i] = i;
            for(int prev = 0 ; prev < i ; prev++){
                if((nums[i] % nums[prev]) == 0){
                    if(dp[i] < 1 + dp[prev]){
                        dp[i] = 1 + dp[prev];
                        hash[i] = prev;
                    }
                } 
            }
                if(dp[i] > maxi){
                    maxi = dp[i];
                    idx = i;
                }
        }
        int i = idx;
        vector<int>ans;
        while(hash[i] != i){
           ans.push_back(nums[i]);
           i = hash[i];
        }
        ans.push_back(nums[i]);
        reverse(nums.begin() ,nums.end());
        return ans;
    }
};
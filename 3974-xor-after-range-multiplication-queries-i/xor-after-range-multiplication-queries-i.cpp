class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        for(int i = 0 ; i < queries.size() ; i++){
            for(int j = queries[i][0] ; j <= queries[i][1] ; j += queries[i][2]){
                long long temp = (1LL * nums[j] * queries[i][3]) % MOD;
                nums[j] = (int) temp;
            }
        }
        int ans = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            ans ^= nums[i];
        }
        return ans;
    }
};
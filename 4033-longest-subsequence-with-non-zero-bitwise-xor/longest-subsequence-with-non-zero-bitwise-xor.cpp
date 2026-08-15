class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int Xor = 0;
        for(int num : nums){
            Xor ^= num;
        }
        bool all_zero = all_of(nums.begin(), nums.end(),[](int x){return x == 0;});
        if(all_zero) return 0;
        if(Xor != 0) return n;
        return n-1;
    }
};
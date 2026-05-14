class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        int target = n-1;
        unordered_map<int,int>freq;
        for(int num : nums){
            freq[num]++;
        }
        for(int i=1; i < target; i++){
            if(freq[i]!=1) return false ;
        }
        return freq[target]==2;
    }
};
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int i = 0 ; i < nums.size() ; i++){
            st.insert(nums[i]);
        }
        int j = 1;
        while(true){
            int curr = k * j;
            if(st.find(curr) == st.end()) return curr;
            j++;
        }
        return -1;
    }
};
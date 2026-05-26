class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int n = nums.size();
        if(n == 0) return 0;
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
        }
        int maxi = 1;
        for(auto it : st){
            int cnt = 0;
            if(st.find(it - 1) == st.end()){
               int x = it;
               while(st.find(x) != st.end()){
                cnt += 1;
                x = x + 1;
               }
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>st;
        int last = 0;
        vector<int>ans;
        for(int i = 0 ; i < nums.size() ; i++){
            while(!st.empty() && nums[i] > nums[st.back()]){
                st.pop_back();
            }
            st.push_back(i);
             if(!st.empty() && st.front() <= i - k) {
                st.pop_front();
            }

           
            if(i >= k - 1) {
                ans.push_back(nums[st.front()]);
            }         
        }
        return ans;
    }
};
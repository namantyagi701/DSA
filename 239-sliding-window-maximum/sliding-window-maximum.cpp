class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        deque<int>dq;
        vector<int>ans;
        while(i < n && j < n){
            while(!dq.empty() && dq.back() < nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);

            while((j - i + 1) > k){
                if(nums[i] == dq.front()) dq.pop_front();
                i++;
            }
            if(j - i + 1 == k)
            ans.push_back(dq.front());
            j++;
        }
        return ans;
    }
};
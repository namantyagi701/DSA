class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        map<int,int>mpp;
        int n = nums2.size();
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            if(st.empty()){
                st.push(nums2[i]);
                mpp[nums2[i]] = -1;
            }
            else{
                mpp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
        }
        vector<int>ans;
        for(int i = 0 ; i < nums1.size() ; i++){
            int x = mpp[nums1[i]];
            ans.push_back(x);
        }
        return ans;
    }
};
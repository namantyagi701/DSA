class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            if(!st.empty() && st.top() < 0) st.push(arr[i]);
            else if(arr[i] > 0) st.push(arr[i]);
            else{
                int ele = abs(arr[i]);
                while(!st.empty() && ele > st.top() && st.top() > 0){
                   st.pop();
                }
                if(!st.empty() && st.top() == ele){
                    st.pop();
                }
                else if(!st.empty() && st.top() > ele){
                    continue;
                }
                else{
                    st.push(arr[i]);
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }        
        reverse(ans.begin() ,  ans.end());
        return ans;
    }
};
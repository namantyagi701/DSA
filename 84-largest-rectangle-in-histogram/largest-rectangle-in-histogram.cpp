class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>st;
        int area = INT_MIN;
        for(int i = 0 ; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int nse = i;
                int element = arr[st.top()];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                area = max(area , element *(nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = arr.size();
            int element = arr[st.top()];
            st.pop();
            int pse = st.empty()? -1 : st.top();
            area = max(area , element *(nse - pse - 1));
        }
        return area;
    }
};
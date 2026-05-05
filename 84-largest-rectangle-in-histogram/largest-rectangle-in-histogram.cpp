class Solution {
public:
    void nse(vector<int>& arr, vector<int>& next) {
        stack<int> st;

        int n = arr.size();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                st.pop();
            }
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }
    void pse(vector<int>& arr, vector<int>& prev) {
        stack<int> st;

        int n = arr.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prev(n , -1);
        vector<int>next(n ,n);
        nse(heights , next);
        pse(heights , prev);

        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            int width = next[i] - prev[i] - 1;
            int area = heights[i] * width;
            maxi = max(maxi , area);
        }
        return maxi;
    }
};
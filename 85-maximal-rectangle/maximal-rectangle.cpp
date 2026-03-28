class Solution {
public:
    int maxArea(vector<int>& arr) {
        stack<int> st;
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int nse = i;
                int element = arr[st.top()];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                maxi = max(maxi, element * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            int nse = arr.size();
            int element = arr[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxi = max(maxi, element * (nse - pse - 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
       
        vector<int> height(m, 0);
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            maxi = max(maxi ,maxArea(height));
        }
        return maxi;
    }
};
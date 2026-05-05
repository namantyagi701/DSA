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
        vector<int> prev(n, -1);
        vector<int> next(n, n);
        nse(heights, next);
        pse(heights, prev);

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            int width = next[i] - prev[i] - 1;
            int area = heights[i] * width;
            maxi = max(maxi, area);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans(m, 0);

       
        for (int j = 0; j < m; j++) {
            ans[j] = matrix[0][j] - '0';
        }

        int maxi = largestRectangleArea(ans);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    ans[j] += 1;
                } else {
                    ans[j] = 0;
                }
            }
            maxi = max(maxi, largestRectangleArea(ans));
        }

        return maxi;
    }
};
class Solution {
public:
    void pse(vector<int>& arr , vector<int>&prev){
        stack<int>st;
        for(int i = 0 ; i < arr.size() ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            prev[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
    }
    void nse(vector<int>& arr , vector<int>& next){
        stack<int>st;
        int n = arr.size();
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            next[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int>prev(n , -1);
        vector<int>next(n , n);
        pse(arr , prev);
        nse(arr, next);
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            int left = prev[i];
            int right = next[i];
            long long curr = ((right - left -1) * arr[i]);
            ans = max(ans , curr);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int>temp(matrix[0].size() , 0);
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == '0') temp[j] = 0;
                else temp[j] += 1;
            }
            int curr = largestRectangleArea(temp);
            ans = max(ans , curr);

        }
        return ans;
    }
};
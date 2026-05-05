class Solution {
public:
    int mod = pow(10,9) + 7;
    void nse(vector<int>& arr, vector<int>& next) {
        stack<int> st;
        int n = arr.size();
        
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
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
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n, -1);
        vector<int> next(n, n);
        nse(arr, next);
        pse(arr, prev);
        
        long long sum = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            int leftEl = i - prev[i];
            int rightEl = (next[i] - i);
            
            sum += (1LL * leftEl * rightEl * arr[i]) % mod;
            
        }
        return sum %mod;
    }
};
class Solution {
public:
    void pse(vector<int> &prev , vector<int>&arr){
        stack<int>st;
        for(int i = 0 ; i < arr.size() ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prev[i] = st.top();
            }
            st.push(i);
        }
    }
    void nse(vector<int> &next , vector<int>&arr){
        stack<int>st;
        int n = arr.size();
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                next[i] = st.top();
            }
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>prev(n , -1);
        vector<int>next(n , n);
        pse(prev , arr);
        nse(next , arr);
        long long sum = 0;
        int MOD = pow(10 , 9) + 7;
        for(int i = 0 ; i < n ; i++){
            int x = i - prev[i];
            int y = next[i] - i;
            sum = (sum + 1LL * x * y * arr[i]) % MOD;
        }
        return sum;
    }
};
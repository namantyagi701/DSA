class Solution {
public:
    void pse(vector<int> &arr , vector<int> & prev){
        stack<int>st;
        for(int i = 0 ; i < arr.size() ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            prev[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
    }

    void nse(vector<int> &arr , vector<int> & next){
        stack<int>st;
        int n = arr.size();
        for(int i = n -1 ; i>= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            next[i] = !st.empty() ? st.top() : n; 
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int>prev(n , -1);
        vector<int>next(n , n);
        pse(arr , prev);
        nse(arr , next);
        long long sum = 0;

        for(int i = 0 ; i < n ; i++){
            int left = i - prev[i];
            int right = next[i] - i;

            sum += (1LL * left * right * arr[i]) % MOD;
        }
        return sum % MOD;
    }
};
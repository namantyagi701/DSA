class Solution {
public:
    int candy(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n , 0);
        // vector<int>right(n , 0);
        //left 
        for(int i = 1 ; i < n ; i++){
            int j = i -1;
            int k = i;
            int cnt = 0;
            while(j >= 0 && k >= 0 && arr[j] < arr[k]){
                 cnt++;
                 j--;
                 k--;
            }
            left[i] = cnt;
        }
        for(int i = n-2 ; i >= 0 ; i--){
            int j = i+1;
            int k = i;
            int cnt = 0;
            while(j < n && k < n && arr[j] < arr[k]){
                 cnt++;
                 j++;
                 k++;
            }
            left[i] = max(left[i] , cnt);
        }
        int ans = 0;
        for(int i = 0 ; i <  n ; i++){
            ans += (left[i] + 1);
        }
        return ans;
    }
};